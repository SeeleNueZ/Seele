// Simplex.cpp : 定义控制台应用程序的入口点。
//
//
/********************************* 
----------------------------------- 
单纯形法求解线性规划问题（C++实现代码）
----------------------------------- 
Author:牧之丶  Date：2014年
Email:bzhou84@163.com 
**********************************/  
#include<stdio.h>
#include<iostream> 
#include<math.h> 
using namespace std;
#define M 10000        //全局变量大M
 float juzhen[11][31];//核心矩阵表 
 int m=0,n=0,t=0;//m:结构向量的个数 //n:约束不等式个数  //t:目标函数类型：－1代表求求最小值，1代表求最大值                          
void input() //输入接口函数
{   
    int i,j; 
    cout<<"－－－－－－－－－－单纯形法的参 数 输 入－－－－－－－－－－－"<<endl; 
    cout<<"请按提示输入下列参数："<<endl<<endl; 
    cout<<"  结构向量数m:  "<<"   m=  "; 
    cin>>m; 
    cout<<endl<<"  约束不等式数n:"<<"   n=  "; 
    cin>>n; 
    for (i=0;i<=n+1;i++) 
    for (j=0;j<=m+n+n;j++)  
         juzhen [i][j]=0;      //初始化矩阵，所有元素均为0
   //读入约束条件 
   cout<<endl<<"  约束方程矩阵的系数及不等式方向（1代表<=,-1代表>=）:"<<endl<<endl<<"          "; 
    for (i=1;i<=m;i++) 
       cout<<"   x"<<i; 
       cout<<"  不等式方向 "<<" 常数项"<<endl; 
    for (i=1;i<=n;i++)  
    {  
      cout<<"    不等式"<<i<<"  "; 
      for (j=1;j<=m+2;j++)  
          cin>>juzhen [i][j]; 
    } 
   for (i=1;i<=n;i++) 
     {  
       juzhen [i][0]=juzhen [i][m+2]; 
       juzhen [i][m+2]=0; 
     } 
  //读入目标条件 
        cout<<endl<<endl<<" 目标函数的系数及类型（求最小值:1；求最大值:-1）:"<<endl<<endl<<"                "; 
   for(i=1;i<=m;i++) 
        cout<<"x"<<i<<"   "; 
        cout<<"类型"<<endl<<"  "; 
        cout<<"  目标函数:   "; 
   for (i=1;i<=m;i++) 
     cin>>juzhen [0][i]; 
     cin>>t; 
  //矩阵调整 
  if(t==-1)  
      for(i=1;i<=m;i++)  
          juzhen [0][i]=(-1)*juzhen [0][i]; 
  for(i=1;i<=n;i++) 
  {  
      juzhen [i][m+i]=juzhen [i][m+1]; 
         if(i!=1) 
             juzhen [i][m+1]=0; 
  } 
} 
//算法函数 
void comput() 
{ 
    int i,j,flag,temp1,temp2,h,k=0,temp3[10]; 
    float a,b[11],temp,temp4[11],temp5[11],f=0,aa,d,c; 
    //初始化 
  for(i=1;i<=n;i++)  
     temp3[i]=0; 
   for(i=0;i<11;i++) 
   {    temp4[i]=0; 
        temp5[i]=0; 
   } 
    for(i=1;i<=n;i++) 
  { 
     if(juzhen [i][m+i]==-1) 
      { 
       juzhen [i][m+n+i]=1; 
       juzhen [0][m+n+i]=M; 
       temp3[i]=m+n+i; 
      } 
     else  
         temp3[i]=m+i; 
  } 
     for(i=1;i<=n;i++) 
           temp4[i]=juzhen [0][temp3[i]]; 
     //循环求解 
do{    
    for(i=1;i<=m+n+n;i++) 
     {   
        a=0; 
        for(j=1;j<=n;j++) 
          a+=juzhen [j][i]*temp4[j]; 
          juzhen [n+1][i]=juzhen [0][i]-a; 
        } 
    for(i=1;i<=m+n+n;i++) 
         { 
            if(juzhen [n+1][i]>=0) flag=1; 
            else  
            {   
                flag=-1; 
                 break; 
             } 
          } 
    if(flag==1) 
    {     for(i=1;i<=n;i++) 
             {  
                  if(temp3[i]<=m+n) temp1=1; 
                           else 
                              {  
                                  temp1=-1; 
                                  break; 
                               } 
              } 
    //输出结果 
    cout<<endl<<endl; 
    cout<<"－－－－－－－－－－结 果 输 出－－－－－－－－－－－"<<endl<<endl; 
        if(temp1==1) 
          {  
             cout<<" 此线性规划的最优解存在!"<<endl<<endl<<"  最优解为："<<endl<<endl<<"     "; 
              for(i=1;i<=n;i++) 
                 temp5[temp3[i]]=juzhen [i][0]; 
              for(i=1;i<=m;i++) 
                 f+=t*juzhen [0][i]*temp5[i];          
              for(i=1;i<=m;i++)  
              { 
                 cout<<"x"<<i<<" = "<<temp5[i]; 
                 if(i!=m) 
                     cout<<"， "; 
              } 
              cout<<" ;"<<endl<<endl<<"     最优目标函数值f= "<<f<<endl<<endl; 
              return ; 
            } 
            else  
            {    
                cout<<" 此线性规划无解"<<endl<<endl; 
                return ; 
            } 
      } 
   if(flag==-1) 
   {    
       temp=100000; 
       for(i=1;i<=m+n+n;i++) 
          if(juzhen [n+1][i]<temp)     
            { 
              temp=juzhen [n+1][i]; 
              h=i;                     
            }               
        for(i=1;i<=n;i++) 
          {  
           if(juzhen [i][h]<=0) temp2=1; 
                else {  
                            temp2=-1; 
                              break; 
                    }                        
          } 
   } 
    if(temp2==1)   
     {  
        cout<<"此线性规划无约束"; 
         return  ; 
     } 
   if(temp2==-1)  
   {    
      c=100000; 
      for(i=1;i<=n;i++) 
        { 
           if(juzhen [i][h]!=0)  b[i]=juzhen [i][0]/juzhen [i][h]; 
           if(juzhen [i][h]==0)  b[i]=100000; 
           if(b[i]<0)     b[i]=100000; 
           if(b[i]<c)  
           { 
              c=b[i]; 
               k=i; 
          } 
      } 
         temp3[k]=h; 
         temp4[k]=juzhen[0][h]; 
         d=juzhen [k][h]; 
      for(i=0;i<=m+n+n;i++) 
        juzhen [k][i]=juzhen [k][i]/d; 
      for(i=1;i<=n;i++) 
      { if(i==k)  
        continue; 
         aa=juzhen [i][h]; 
         for(j=0;j<=m+n+n;j++) 
           juzhen [i][j]=juzhen [i][j]-aa*juzhen [k][j];  
      } 
   }     
} 
while(1); 
     return ; 
}

int main()
{   cout<<"-------------------单纯形算法程序----------------------"<<endl<<endl; 
  input(); 
  comput();
  system("pause");
    return 0;
}
