#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
default_random_engine e;
uniform_int_distribution<int> u(1, 20);

int n;   // 矩阵个数
int *p;  // 矩阵的维数
int **m; // 子链的数乘次数，初始值为0
int **s; // 子链的断开位置k

void MatrixChain(int n, int *p, int **m, int **s);
void DataInput();
void Traceback(int **s, int i, int j);

int main()
{
    e.seed(time(0));
    n=10; //n个矩阵，n+1个大小
    //int w[6]={1,6,3,6,5,1};
    
    p=new int[n+1];
    for(int i=0;i<n+1;i++)
    {
        p[i]=u(e);
        cout<<p[i]<<" ";
    }
    cout<<endl;
    
    m = new int* [n + 1];   // 子链的数乘次数，初始值为0
    for (int i = 0;i < n + 1;i++) 
    {
        m[i] = new int[n + 1];
        for (int j = 0;j < n + 1;j++)
            m[i][j] = 0;
    }
    s = new int* [n + 1];   // 子链的断开位置k
    for (int i = 0;i < n + 1;i++)
    {
        s[i] = new int[n + 1];
    }
    MatrixChain(n, p, m, s);
    // 输出
    cout << "ans:" << m[1][n] << endl;
    Traceback(s, 1, n);    
}

void MatrixChain(int n, int *p, int **m, int **s)
{
    // r代表子链长度
    for (int r = 2; r <= n; r++)
    {
        // i从1开始，一直到n-r+1，
        // i表示每一个区间长度为r的区间左端点，
        // i=n-r+1是最后一左个端点，此时区间表示为[n-r+1,n]，长度为r
        for (int i = 1; i <= n - r + 1; i++)
        {
            // j表示区间右端点
            int j = i + r - 1;
            // 这个划分是默认的加上第一个，也就是从第一个之后断开，从第k个断开=第k个和之前一组，别的一组
            m[i][j] = m[i][i] + m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            // 计算所有划分，看哪个小于先前的划分
            for (int k = i + 1; k < j; k++)
            {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

void DataInput()
{
}

void Traceback(int **s, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
    Traceback(s, i, s[i][j]);
    Traceback(s, s[i][j] + 1, j);
    cout << ")";
}