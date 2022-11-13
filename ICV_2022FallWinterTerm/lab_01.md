# Lab 01. Python, OpenCV Tutorial

## Requirements

`conda` 等安装一切正常。

课程要求使用 `python3.7` && `open3d0.9`，然而 Mac M1 根本不支持这两个版本，于是只能硬着头皮装了 `python3.8` && `open3d1.4`。

```shell
conda create -n ICV_LAB python=3.8
conda activate ICV_LAB
pip install open3d==1.4
pip install jupyter
pip install matplotlib
pip install imageio
pip install opencv-python
```



## Tasks

1. 完成8个TAG中的函数，得到和notebook中一样的输出
    1. 使用 `matplotlib` 显示图片
    2. 用 `subplot` 显示两张图片
    3. 用 `matplotlib` 显示拼接图片
    4. 使用 `matplotlib` 绘制一个函数
    5. 使用 `opencv` 转换并显示图片
    6. 使用 `opencv` 读取并显示视频
    7. 使用 `opencv` 在图片中间写上你的学号并保存至result.png
    8. 使用 `Open3d` 读取和显示模型
2. 替换code目录中lena.png为自己的图片，重新执行一遍

## Notes

### Task 1.1

没啥，就用了一下 `plt.imshow()`

### Task 1.2

`sub_plot` 的相关内容，三个参数 `(a, b, c)` 表示 a 行 b 列中的第 c 个

### Task 1.3

`numpy` 的 `concatenate()` ，沿着宽度轴连接

#### Task 1.4

大致就是将点的横纵坐标分别形成一个数组，然后将数组当作坐标参数输入，最后会将点连成曲线

如果直接 `arange` 的话感觉不太平滑，所以多插了几个点进去

### Task 1.5

使用 `cv2` 的一些函数来进行通道转化和输出，主要需要注意的是 `waitKey()` ，可以理解为用它来做一个阻塞，第一个 `waitKey(0)` 是指无条件阻塞，一直到有键盘事件输出键盘的代码；`waitKey(1)` 则是阻塞 1ms，如果有键盘事件会输出键盘的代码；在这里只有阻塞效果，即等待用户确认第一张图片以后再显示第二张

### Task 1.6

比较坑的是需要在最后手动加一个 `waitKey(1)` 否则会炸，然后播放视频的本质实际上就是一张图片一张图片的显示，还是比较好理解的

### Task 1.7

主要就是 `putText()` 函数，我在注释里解释了各个参数的含义

顺便还用到了 `img.shape` 来获取中心坐标

### Task 1.8

版本不合适，mac 做不了。问了下旭宝，他说之后没怎么用到。我估计之后都直接脱离 jupyter 了所以不需要用这个工具了。所以我直接不管了。
