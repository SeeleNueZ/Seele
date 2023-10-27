import numpy as np
from numpy import tile


def multiply(a, b):
    da = np.shape(a)[0]
    # 使用了一个简单的数学变化原理，从[i,j]变成[k,i,j],k加到前面了
    # i是行，j是列，A是每一层按j维度（按某一列）复制，成为一个n*n的层，然后叠出来一个n*n*n
    # 最后的结果就是在[i,k]面上形成了初始的矩阵，等效于这个矩阵自我复制n遍，下面是根据这句话写的
    # 注意I,J,K的关系，和从立方体抽象出矩阵后的行列关系
    # 见配图
    # 转置交换i，j，因为最后是i，j映射到i，k，但是数组顺序是k，i，j，要交换一下
    a = a.transpose()
    a1 = np.expand_dims(a, axis=2)
    # print(a1)
    a1 = np.tile(a1, (1, 1, da))  # 具有迷惑性的一点，理论上的第二维因为顺序的问题是第三个，复制所以要在第三维复制
    # print(a1)
    db = np.shape(b)[1]
    # b就是换一个方向，别的一样
    b1 = np.expand_dims(b, 1).repeat(db, axis=1)
    # print(b1)
    c1 = np.ones((da, da, da))
    for i in range(0, da):
        for j in range(0, da):
            for k in range(0, da):
                c1[i, j, k] = a1[i, j, k] * b1[i, j, k]
    # print(c1)
    # 对k维度求和
    c1 = c1.sum(axis=0)
    print("c:")
    print(c1)


def test():
    a1 = np.array([1])
    a2 = np.array([1, 2, 3])
    a3 = np.array([1, 2])
    c = np.array([a1, a2, a3])


if __name__ == '__main__':
    # test()
    am1 = np.array([[1, 2], [4, 5]])
    bm1 = np.array([[0, 1], [0, 2]])
    am2 = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    bm2 = np.array([[0, 1, 2], [0, 2, 4], [0, 3, 6]])
    multiply(am1, bm1)
    multiply(am2, bm2)
    at1 = np.mat([[1, 2], [4, 5]])
    bt1 = np.mat([[0, 1], [0, 2]])
    at2 = np.mat([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    bt2 = np.mat([[0, 1, 2], [0, 2, 4], [0, 3, 6]])
    print(np.dot(at1, bt1))
    print(np.dot(at2, bt2))
