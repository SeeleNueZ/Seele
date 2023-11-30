#include<algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
#include <iostream>

using namespace std;

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

    for(int i=0;i<((sizeof(arr)/sizeof(int)));i++)
    {
        cout<<i+1<<":"<<arr[i]<<endl;
    }
    return 0;
}