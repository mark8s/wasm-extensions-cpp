# wasm-extensions-cpp
use c++ build  envoy wasm

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

















