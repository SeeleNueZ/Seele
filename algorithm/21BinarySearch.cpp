#include<algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
#include <iostream>

using namespace std;

int Search(int a[],int x,int n)
{
    int l=0;
    int r=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(x==a[mid])
        {
            return mid+1;
        }
        else if(x >a[mid])
        {
            l=mid+1;
        }
        else if(x<a[mid])
        {
            r=mid-1;
        }
    }
    return -1;

}

int main()
{
    default_random_engine e;
    uniform_int_distribution<int> u(0,100);
    e.seed(time(0));
    int arr[50]={0};
    for(int i=0;i<((sizeof(arr)/sizeof(int)));i++)
    {
        arr[i]=u(e);
    }
    sort(arr,arr+50);

    cout<<Search(arr,20,50)<<endl;
    
    for(int i=0;i<((sizeof(arr)/sizeof(int)));i++)
    {
        cout<<i+1<<":"<<arr[i]<<endl;
    }
    
    return 0;
}