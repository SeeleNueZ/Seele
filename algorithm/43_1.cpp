#include<iostream>
#include<string>
using namespace std;
#define MVNum 100
#define MAXInt 32767//定义无穷大
typedef  string VerTexType;
typedef int ArcType;
/*----------图的邻接矩阵表示法存储结构---------*/
typedef struct {
	int arcnum, vexnum;//顶点数和边数
	VerTexType vex[MVNum];//定义存储顶点的数组
	ArcType arcs[MVNum][MVNum];//定义存储边的数组 
}AMGraph;
/*-------辅助数组的定义，用来记录从顶点集U到V-U的权值最小的边-------*/
typedef struct 
{
	VerTexType adjvex;//最小边在U中的那个顶点
	ArcType lowcost;//最小边上的权值
}MinEdge;
MinEdge closedge[MVNum];
/*----------在顶点表中找到传入顶点的位置---------*/
int LocateVex(AMGraph G, VerTexType v) {
	//遍历顶点表，返回某顶点在顶点表中的位置下标
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vex[i] == v)//在顶点表中找到了顶点v
			return i;//返回其下标
	}
	return -1;//没找到返回-1
}
/*---------采用邻接矩阵表示法创建无向网-------*/
void CreateUDN(AMGraph& G) {
	//采用邻接矩阵表示法，创建无向网
	int i = 0, j = 0, k = 0, w;
	cin >> G.vexnum >> G.arcnum;//输入总顶点数，总边数
	for (i = 0; i < G.vexnum; i++)//依次输入点的信息
		cin >> G.vex[i];
	for (i = 0; i < G.vexnum; i++)//初始化邻接矩阵
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = MAXInt;
	for (k = 0; k < G.arcnum; k++) {
		VerTexType v1, v2;//定义两个顶点v1,v2
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);//确定v1和v2在G中的位置，即顶点数组的下标
		G.arcs[i][j] = G.arcs[j][i] = w;
	}
}
/*--------在辅助数组中找到lowcost最小的顶点-------*/
int Min(MinEdge closedge[],int size) {
	//取最小权值边的顶点位置
	int k = -1;//最后接收最小权值邻接点的下标
	for (int i = 0; i < size; i++) {
		if (closedge[i].lowcost > 0) {//i号顶点并未被归入到生成树中
			int min = closedge[i].lowcost;//设置min中间变量存放最小权值
			for (int j = i; j < size; j++) {
				if (closedge[j].lowcost > 0 && min >= closedge[j].lowcost) {
					min = closedge[j].lowcost;
					k = j;
				}
			}
			break;
		}
	}
	return k;
}
/*------------构造最小生成树的Prim算法----------*/
void MiniSpanTree_Prim(AMGraph G, VerTexType u) {
	//无向网G以邻接矩阵形式存储，从顶点u出发构造G的最小生成树T，输出T的各条边
	int k = LocateVex(G, u);//k为顶点u的下标
	for (int j = 0; j < G.vexnum; j++) {
		//对V-U的每一个顶点vj，初始化closedge[j]
		closedge[j].adjvex = u;//{adjvex,lowcost}
		closedge[j].lowcost = G.arcs[k][j];
	}
	closedge[k].lowcost = 0;//初始,U={u}
	for (int i = 1; i < G.vexnum; i++) {
		//选择其余n-1个结点，生成n-1条边（n=G.vexnum）
		int k = Min(closedge,G.vexnum);
		//求出T的下一个结点；第k个顶点,closedge[k]中存有当前最小边
		ArcType u0 = closedge[k].lowcost;//u0为最小边的一个顶点,u0属于u
		VerTexType v0 = G.vex[k];//v0为最小边的另一个顶点，v0属于V-U
		cout << u0 << " " << v0 << endl;//输出当前的最小边(u0,v0);
		closedge[k].lowcost = 0;//第k个顶点并入U集
		for (int j = 0; j < G.vexnum; j++) {
			if (G.arcs[k][j] < closedge[j].lowcost)//新顶点并入U后重新选择最小边
			{
				closedge[j].adjvex = G.vex[k];
				closedge[j].lowcost = G.arcs[k][j];
			}
		}
	}
}
int main() {
	AMGraph G;
	CreateUDN(G);
	int v = 0;
	MiniSpanTree_Prim(G,G.vex[v]);
	return 0;
}