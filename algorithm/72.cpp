#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
#define N 10

bool Majority(int *T, int len, int &num)
{
    int n = rand()%10;
    num = T[n];
    int cnt = 0;
    for(int i=0; i<len; i++)
    {
        if(T[i] == num)
            cnt++;
    }
    return (cnt>len/2);
}

bool MajorityMC(int *T, int len, double e, int &num)
{
    int k = ceil(log(1/e)/log((float)2));
    for(int i=0; i<k; i++)
    {
        if(Majority(T, len, num))
            return true;
    }
    return false;
}

int main()
{
    int num=INT_MAX;
    float e = 0.001;
    int T[N]={5,5,5,5,5,5,1,3,4,6};
    cout<<"数组T的元素如下："<<endl;
	for(int i=0; i<N; i++)
	{
		cout<<T[i]<<" ";
	}
	cout<<endl;
    if(MajorityMC(T,N,e,num))
        cout << "该数组的主元素为：" << num << endl;
    else
        cout << "该数组没有主元素" << endl;
    return 0;
}