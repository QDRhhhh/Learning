# 中文版本

## 描述

- 本部分数据将满足以下条件：
    1. B 中的“图形”由 A 中的“图形”通过刚性变化得到，即只有整体缩放、旋转、翻转；
    2. B 中的图形会存在“弯折”；
    3. 不存在噪点；
    4. 以上条件意味着，在此部分数据中，A 和 B 中点的数量应当是相同的。

- 比较遗憾的是，这里的数据测试表现并不十分理想，因为当生成的图形相当接近，可能少数几个点就会导致他们的得分产生突变，而我只有时间处理两阶的情况。如果采用我在报告中使用的“邻域方差突变检测”来找到突变点，效果会好很多，甚至能够找到有多少个特征是能够被匹配的。

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
    1. Polygon in B is rigid transformed(i.e. scale, rotate and flip) from that in A.
    2. Polygon in B will have a "bend".
    3. There will be no noise.

- Unfortunately, the performance of the data test here is not very good, because when the generated graphs are quite close, there may be a few points that cause their scores to mutate, and I only had time to deal with the two-order case. It would have been much better to use the "neighborhood variance mutation detection" I used in the report to find the mutation points, and even to find how many features could be matched.

## Data Form

In `.in` file,

- The first line is an integer *T*, which means there will be *T* groups of test data.
- Then comes *T* groups of data. In each group:
  - Line *1* contains an integer *m*, which means there are *m* points in *A*.
  - Line *2* to line *m+1*, contains two float number *x* and *y* each line, which represents the coordinate of the point.
  - Line *m+2* contains an integer *n*, which means there are *n* points in *B*.
  - Line *m+3* to line *m+n+2*, contains two float number *x* and *y* each line, which represents the coordinate of the point.
