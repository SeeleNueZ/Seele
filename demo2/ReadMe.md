提取运行时间参考https://zhuanlan.zhihu.com/p/349949616

没有使用openmp

![204215](E:\GitHub\Seele\demo2\pic\204215.png)

启用openmp

![204257](E:\GitHub\Seele\demo2\pic\204257.png)

*上述两个版本没有使用for中的j循环

在使用for中的j循环后，

不是有openmp会变成25s

单纯的启用openmp则会变成72.917s，应该是出现了使用方法bug？

截图也在pic下面
