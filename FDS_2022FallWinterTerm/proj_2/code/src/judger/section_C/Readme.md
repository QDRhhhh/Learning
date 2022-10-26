# 中文版本

## 描述

- 本部分数据将满足以下条件：
    1. B 中的“图形”首先由 A 中的“图形”通过刚性变化得到，即只有整体缩放、旋转、翻转；
    2. 然后对其中的点进行一定程度的扰动，即每个点都会被加上一个随机向量；
    3. 除此之外，我还会添加若干噪点，噪点的数量在原图点数的 4 倍以内；
    4. 以上条件意味着，在此部分数据中，A 和 B 中点的数量应当是相同的；

## 数据范式

`.in` 文件中

- 第一行为一个整数 T，表示有 T 组测试数据；
- 接下来为 T 组数据：
  - 每组第 1 行为一个整数 m，表示 A 中有 m 个点；
  - 每组第 2 ~ m+1 行，每行有两个浮点数 x 和 y，表示每个点的坐标；
  - 每组第 m+2 行为一个整数 n，表示 B 中有 n 个点；
  - 每组第 m+3 ~ m+n+2 行，每行有两个浮点数 x 和 y，表示每个点的坐标；

---


# English Version

## Description

- Data made here will have following features:
    1. Polygon in B is first rigid transformed(i.e. scale, rotate and flip) from that in A.
    2. Then each points in B will be randomly added by a random vector.
    3. What's more, I will also add some noise points, whose number will no bigger than 4 times of that of the origin points.
    4. There will be no noise.

## Data Form

In `.in` file,

- The first line is an integer *T*, which means there will be *T* groups of test data.
- Then comes *T* groups of data. In each group:
  - Line *1* contains an integer *m*, which means there are *m* points in *A*.
  - Line *2* to line *m+1*, contains two float number *x* and *y* each line, which represents the coordinate of the point.
  - Line *m+2* contains an integer *n*, which means there are *n* points in *B*.
  - Line *m+3* to line *m+n+2*, contains two float number *x* and *y* each line, which represents the coordinate of the point.
