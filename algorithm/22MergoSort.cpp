#include<algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
#include <iostream>

using namespace std;
default_random_engine e;
uniform_int_distribution<int> u(0,100);

void printx(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        //cout<<i+1<<":"<<arr[i]<<endl;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void generate(int arr[],int n)
{
    e.seed(time(0));
    for(int i=0;i<n;i++)
    {
        arr[i]=u(e);
    }
}
void Merge(int x[],int y[],int l,int m,int r)//l,m是第一段，m+1.r是第二段
{
    int i=l,j=m+1,k=l;///注意几个变量初始位置，尤其是这个k
    while ((i<=m) && (j<=r))
    {
        if(x[i]<=x[j])
        {
            y[k]=x[i];
            k++;
            i++;
        }
        else
        {
            y[k]=x[j];
            k++;
            j++;
        }
    }
    if(i>m)
    {
        for(int p1=j;p1<=r;p1++)
        {
            y[k]=x[p1];
            k++;
        }
    }
    else if(j>r)
    {
        for(int p1=i;p1<=m;p1++)
        {
            y[k]=x[p1];
            k++;
        }
    }
    
}
void MergePass(int x[],int y[],int s,int n) //两两合并的思路，s指定了每一段多长，最后是两个s长度内排好了（两个s合成一段）。
{
    int i=0;
    //printx(y,n);
    while(i<=n-2*s)
    {
        Merge(x,y,i,i+s-1,i+2*s-1);
        //cout<<"s:"<<s<<",i:"<<i<<" ";
       // printx(y,n);
        i=i+2*s;
    }
    if(i+s<n) //等于就说明还有多的一个 0.。。。s-1,1
    {
        Merge(x,y,i,i+s-1,n-1);
    }
    else
    {
        for(int j=i;j<n;j++)
        {
            y[j]=x[j];
        }
    }
}

void Sort(int a[],int n)  //本体，负责对整个数据进行归并，Pass中间指定的参数为，原数组，目标数组，归并大小（s长与s长边上的两个进行归并），整体长度
{
    int *b=new int[n];
    int s=1;
    while(s<n)
    {
        MergePass(a,b,s,n);
      //  cout<<"s:"<<s<<endl;
       // printx(b,n);
        s=s*2;
        MergePass(b,a,s,n);
       // printx(a,n);
        s=s*2;
    }
}
int main()
{
    int arr[50]={0};
    int ans[50]={0};
    int n=sizeof(arr)/sizeof(arr[0]);
    generate(arr,n);
    printx(arr,n);
    Sort(arr,n);
    printx(arr,n);
    
}