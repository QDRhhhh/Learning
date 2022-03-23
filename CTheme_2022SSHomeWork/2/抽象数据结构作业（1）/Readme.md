# 抽象数据结构作业（1）

## 使用

1. 输入 `make` 编译代码
2. 输入 `./run.exe <mod> <log>` 来运行对应代码
   1. `<mod>`为必填参数，有三个可用值：`n` `i` `p`，分别对应正常、过量`Enqueue`、过量`Dequeue`
   2. `<log>`为可选参数，有一个可用值：`l`，输入表示打印日志
- 例如：`./run.exe n l`表示正常运行代码，并且输出日志

## 代码内容说明

- 调整`queue.h`中的`MAXN`调整整个程序所能容纳的最多新queue数量；
- 调整`queue.h`中的`MAXNQ`调整一个queue中最多的buffer size
