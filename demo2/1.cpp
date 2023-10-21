#include<iostream>
#include<algorithm>
#include<ctime>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    auto time1 = high_resolution_clock::now();
    unsigned long long int n=10000000000;
    unsigned long long int sum=0;
    unsigned long long int i=0;
    int j=0;
    cout << dec << "unsigned long long最大值：" << ULLONG_MAX <<endl;
    for(i=0;i<n;i++)
    {
        //sum +=i;
        //写了一点拖时间的东西,累加应该会溢出
        sum++;
       // for(j=0;j<2;j++);
        
    }
    auto time2 = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(time2 - time1);
    auto durs=double(duration.count())*1e-9;
    cout<<"sum:"<<sum<<endl;
    printf("Time measured: %.3f seconds.\n", durs);
    return 0;
}