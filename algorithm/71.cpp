#include <stdlib.h>
#include <stdio.h> 
#include <time.h> 


int main(){


    srand((unsigned) time(NULL)); //随机数种子 
    int n;
    double x,y,distance; 
    int count=0;
    printf("please input the number of times:");
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        x = rand()/(double)(RAND_MAX); //x产生0-1的随机数
        y = rand()/(double)(RAND_MAX); //y产生0-1的随机数

        distance=(x-1)*(x-1)+(y-1)*(y-1);
        if(distance<=1.0){
            count++;
        }
    }
    printf("PI=%lf",(2.0*2*count)/n);
}