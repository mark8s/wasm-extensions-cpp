# data clean
这是一个修改responseBody的demo。

## 文件说明

config/envoyfilter.yaml: 是部署EnvoyFilter的文件

plugin.cc、plugin.h: wasm的核心logic

## 构建
```shell
bazel build //:data-clean.wasm
```




