# 中文版本

## 描述

- 本部分数据将满足以下条件：
    1. B 中的“图形”由 A 中的“图形”通过刚性变化得到，即只有整体缩放、旋转、翻转；
    2. 不存在噪点；
    3. 以上条件意味着，在此部分数据中，A 和 B 中点的数量应当是相同的。

## 数据范式

每一份输出数据都包含 `.in` 和 `.info` 两个文件

`.in` 文件中

- 第一行为一个整数 T，表示有 T 组测试数据；
- 接下来为 T 组数据：
  - 每组第 1 行为一个整数 m，表示 A 中有 m 个点；
  - 每组第 2 ~ m+1 行，每行有两个浮点数 x 和 y，表示每个点的坐标；
  - 每组第 m+2 行为一个整数 n，表示 B 中有 n 个点；
  - 每组第 m+3 ~ m+n+2 行，每行有两个浮点数 x 和 y，表示每个点的坐标；

`.info` 文件中

- 第一行为一个整数 T，表示有 T 组测试数据；
- 接下来为 T 组信息：
  - 每组第 1 行为一个整数 k，表示有 k 条对应关系；
  - 每组第 2 ～ k+1 行，每行有两个整数 u 和 v，表示原始数据中 A 中 u 号点与 B 中 v 号点对应，对应关系满足题目中描述的单调关系；

---


# English Version

## Description

- Data made here will have following features:
    1. Polygon in B is rigid transformation(i.e. scale, rotate and flip) by that in A.
    2. There will be no noise.

## Data Form

Each output consists of `.in` and `.info` files.

In `.in` file,

- The first line is an integer *T*, which means there will be *T* groups of test data.
- Then comes *T* groups of data. In each group:
  - Line *1* contains an integer *m*, which means there are *m* points in *A*.
  - Line *2* to line *m+1*, contains two float number *x* and *y* each line, which represents the coordinate of the point.
  - Line *m+2* contains an integer *n*, which means there are *n* points in *B*.
  - Line *m+3* to line *m+n+2*, contains two float number *x* and *y* each line, which represents the coordinate of the point.

In `.info` file,

- The first line is an integer *T*, which means there will be *T* groups of test data information.
- Then comes *T* groups of data information. In each group:
  - Line *1* contains an integer *k*, which means there are *k* correspondences.
  - Line *2* to line *k+1*, contains two float number *u* and *v* each line, which represents the point *A[u]* and point *B[v]* is matched, and the correspondence satisfies the monotonic relation described in the question.
