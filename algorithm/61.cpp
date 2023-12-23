#include <iostream>
#include <stdio.h>
#include<queue>
using namespace std;

int len[100];
int num=0;

typedef struct ArcCell{
    int adj;//保存权值
    int info;//存储最短路径长度
}ArcCell,AdjMaxtrix[100][100]; // 定义同性不同名的结构体

typedef struct{ //定义每个点的编号和最短路径数值
    int data;
    int length;
}VerType;

typedef struct{
    VerType vexs[100];//顶点向量
    AdjMaxtrix arcs;
    int vexnum;//顶点数
    int arcnum;//弧数
}Graph;

Graph G;
queue<int> q;

void CreateGraph()
{
    int m,n,t;
    G.vexnum=11;
    G.arcnum=19;
//    printf("输入顶点数和弧数:");
//    scanf("%d%d",&G.vexnum,&G.arcnum);
//    printf("输入顶点:");
    for(int i=1;i<=G.vexnum;i++)
    {
//        scanf("%d",&G.vexs[i].data);
        G.vexs[i].data=i;
        G.vexs[i].length=10000;
    }

    for(int i=1;i<=G.vexnum;i++)
        for(int j=1;j<=G.vexnum;j++)
        {
            G.arcs[i][j].adj=0;
        }

//    printf("输入弧及权重:\n");
//    for(int i=1;i<=G.arcnum;i++)
//        {
//            scanf("%d%d%d",&m,&n,&t);
//            G.arcs[m][n].adj=1;
//            G.arcs[m][n].info=t;
//        }
        G.arcs[1][2].adj=1;
        G.arcs[1][2].info=2;

        G.arcs[1][3].adj=1;
        G.arcs[1][3].info=3;

        G.arcs[1][4].adj=1;
        G.arcs[1][4].info=4;

        G.arcs[2][5].adj=1;
        G.arcs[2][5].info=7;

        G.arcs[2][6].adj=1;
        G.arcs[2][6].info=2;

        G.arcs[2][3].adj=1;
        G.arcs[2][3].info=3;

        G.arcs[3][6].adj=1;
        G.arcs[3][6].info=9;

        G.arcs[3][7].adj=1;
        G.arcs[3][7].info=2;

        G.arcs[4][7].adj=1;
        G.arcs[4][7].info=2;

        G.arcs[5][8].adj=1;
        G.arcs[5][8].info=3;

        G.arcs[5][9].adj=1;
        G.arcs[5][9].info=3;

        G.arcs[6][9].adj=1;
        G.arcs[6][9].info=3;

        G.arcs[6][7].adj=1;
        G.arcs[6][7].info=1;

        G.arcs[7][9].adj=1;
        G.arcs[7][9].info=1;

        G.arcs[7][10].adj=1;
        G.arcs[7][10].info=1;

        G.arcs[8][11].adj=1;
        G.arcs[8][11].info=3;

        G.arcs[9][11].adj=1;
        G.arcs[9][11].info=2;

        G.arcs[10][11].adj=1;
        G.arcs[10][11].info=2;

        G.arcs[10][9].adj=1;
        G.arcs[10][9].info=2;



}
//   k    =     t     k
int NextAdj(int v,int w)
{
    for(int i=w+1;i<=G.vexnum;i++)
        if(G.arcs[v][i].adj)
            return i;
    return 0;//not found;
}
int NextAdj2(int i)
{
    for(int j=i-1;j>0;j--)
    {
        if(G.arcs[j][i].adj==1&&(G.vexs[i].length-G.arcs[j][i].info==G.vexs[j].length))
        {
            G.arcs[j][i].adj=0;
            return j;
            break;
        }
    }
}
void Print2()
{
    int i=G.vexnum;
    while(G.vexs[i].length!=0)
    {
        int j=NextAdj2(i);
        len[num]=j;
        num++;
        i=j;



    }
    cout<<endl;
    for(int x=num-1;x>=0;x--)
    {
        cout<<len[x]<<" ";
    }
    num=0;
    cout<<endl;
}

//
//void clean ()
//{
//
//    for(int i=1;i<=G.arcnum;i++)
//    {
//        for(int j=1;j<=G.arcnum;j++)
//        {
//            if(G.arcs[i][j].info!=0)
//            G.arcs[i][j].adj=1;
//
//        }
//    }
//
//}

void ShortestPaths(int v)
{
    int k=0;//从首个节点开始访问
    int t;
    G.vexs[v].length=0;
    q.push(G.vexs[v].data);
    while(!q.empty())
    {
        t=q.front();
        k=NextAdj(t,k);// k是选择出来相连的结点
        while(k!=0)
        {
            if(G.vexs[t].length+G.arcs[t][k].info<=G.vexs[k].length)//减枝操作
            {
                G.vexs[k].length=G.vexs[t].length+G.arcs[t][k].info;
                q.push(G.vexs[k].data);
            }
            k=NextAdj(t,k);
        }
        q.pop();
    }
}

void Print()
{
    for(int i=1;i<=G.vexnum;i++)
        printf("%d------%d\n",G.vexs[i].data,G.vexs[i].length);
}


int main()
{
    CreateGraph();
    ShortestPaths(1);
    Print();
    Print2();
    return 0;
}
