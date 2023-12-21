#include <stdio.h>
int x[100],bestx[100],m[100][100];//m[j][i]表示在第i台机器上作业j的处理时间
//数组bestx记录相应的当前最佳作业调度。
int f1=0,f2,cf=0,bestf=10000,n;  //bestf记录当前最小完成时间和
void swap(int *x,int t,int j)
{
    int temp = x[t];
    x[t] = x[j];
    x[j] = temp;
}

void Backtrack(int t)
{
    int tempf,j,i;
    if(t>n) //到达叶子结点，搜索到最底部
    {
        for( i=1; i<=n; i++)
        {
            bestx[i]=x[i];
        }
        bestf=cf;

    }
    else    //非叶子结点
    {
        for(j=t; j<=n; j++)
        {
            f1+=m[x[j]][1];  //记录作业在第一台机器上的完成处理时间
            tempf=f2;//保存上一个作业在机器2的完成处理时间
            f2=(f1>f2?f1:f2)+m[x[j]][2];//保存当前作业在机器2的完成时间
            cf+=f2;               //cf记录当前在机器2上的完成时间和
            if(cf<bestf)
            {
                swap(x,t,j);  //交换两个作业的位置
                Backtrack(t+1);
                swap(x,t,j);
            }
            f1-=m[x[j]][1];
            cf-=f2;
            f2=tempf;
        }
    }
}


int main()
{
    int i,j;

    printf("请输入作业数量\n");
    scanf("%d",&n);
    printf("请输入在各机器上的处理时间\n");
    for(i=1; i<=2; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&m[j][i]);
        }
    }
    for(i=1; i<=n; i++)
    {
        x[i]=i;  //记录当前调度
    }
    Backtrack(1);

    printf("调度作业顺序\n");
    for(i=1; i<=n; i++)
    {
        printf("%d\t",bestx[i]);
    }
    printf("\n");
    printf("处理时间:\n");
    printf("%d\n",bestf);
    return 0;
}
