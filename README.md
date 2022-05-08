# wasm-extensions-cpp
记录使用c++ 编写Envoy wasm的过程。

## Installation
On Linux, run the following commands:

Install `Bazelisk` as Bazel
```shell
sudo wget -O /usr/local/bin/bazel https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64
sudo chmod +x /usr/local/bin/bazel
```
Installing Minimum Dependencies.On Ubuntu, run the following command:
```shell
sudo apt-get install gcc curl python3
```

## Develop a Wasm extension with C++
这部分的内容参考 [Develop a Wasm extension with C++](https://github.com/istio-ecosystem/wasm-extensions/blob/master/doc/write-a-wasm-extension-with-cpp.md)
需要了解`Bazel`相关的知识。

`Bazel`是一种编译工具, 类似Maven, [istio-ecosystem/wasm-extensions/extensions](https://github.com/istio-ecosystem/wasm-extensions/tree/master/extensions) 目前的例子都是使用它去编译代码成wasm文件的。

简单开发一个C++的wasm extensions过程就是copy里面例子中的WORKSPACE与BUILD文件，然后修改plugins.cc与plugins.h文件的logic，再使用`Bazel`编译成wasm文件，最后由EnvoyFilter引用到sidecar中。

## 问题解决

1. bazel could not resolve the version 'latest'

报错详情： 
``` shell
root@13:~/wasm-extensions/example# bazel build //:example.wasm
2022/05/06 02:48:58 could not resolve the version 'latest' to an actual version number: unable to determine latest version: could not list Bazel versions in GCS bucket: could not list GCS objects at https://www.googleapis.com/storage/v1/b/bazel/o?delimiter=/: could not fetch https://www.googleapis.com/storage/v1/b/bazel/o?delimiter=/: Get "https://www.googleapis.com/storage/v1/b/bazel/o?delimiter=/": read tcp 10.10.13.47:33302->172.217.160.106:443: read: connection reset by peer
```
解决办法：在当前目录下执行一下命令
```shell
echo "USE_BAZEL_VERSION=4.1.0" > .bazeliskrc
```
完事后，执行以下命令校验

```shell
root@13:~/wasm-extensions/example# bazel version
Bazelisk version: v1.11.0
Build label: 4.1.0
Build target: bazel-out/k8-opt/bin/src/main/java/com/google/devtools/build/lib/bazel/BazelServer_deploy.jar
Build time: Fri May 21 11:11:34 2021 (1621595494)
Build timestamp: 1621595494
Build timestamp as int: 1621595494
```

















