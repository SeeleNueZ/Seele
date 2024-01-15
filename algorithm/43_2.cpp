#include<iostream>
#include<string>
#include<algorithm>
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
/*-----------辅助数组Edges的定义--------------*/
typedef struct edge{
	VerTexType Head;//边的始点
	VerTexType Tail;//边的终点
	ArcType lowcost;//边上的权值
}Edgea;
Edgea Edge[MVNum];
/*---------辅助数组Vexset的定义------------*/
int Vexset[MVNum];
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
		Edge[k].Head = v1;
		Edge[k].Tail = v2;
		Edge[k].lowcost = w;
	}
}
/*-----获取图的边数---------*/
int getArcnum(int n) {//获取图的边数
	return n;
}

bool cmd(edge a,edge b) {
	return a.lowcost < b.lowcost;
}
/*----------Kruskal算法的代码实现----------*/
void MiniSpanTree_Kruskal(AMGraph& G) {
	//无向网G以邻接矩阵形式存储，构造G的最小生成树T，输出T的各条边
	sort(Edge, Edge + G.arcnum, cmd);//将数组Edge中的元素按权值从小到大排序
	int sum = 0;
	for (int i = 0; i < G.vexnum; i++)//辅助数组，表示各顶点自成一个连通分量
		Vexset[i] = i;
	for (int i = 0; i < G.arcnum; i++) {//依次查看数组Edge中的边
		int v1, v2 = 0;
		v1 = LocateVex(G, Edge[i].Head);//v1为边的始点Head的下标
		v2 = LocateVex(G, Edge[i].Tail);//v2为边的终点Tail的下标
		int vs1, vs2 = 0;
		vs1 = Vexset[v1];//获取边Edge[i]的始点所在的连通分量vs1
		vs2 = Vexset[v2];//获取边Edge[i]的终点所在的连通分量vs2
		if (vs1 != vs2) {//边的两个顶点分属不同的连通分量
			cout << Edge[i].Head <<" "<< Edge[i].Tail <<" "<< Edge[i].lowcost << endl;//输出此边
			for (int j = 0; j < G.vexnum; j++) {//合并vs1和vs2两个分量，即两个集合统一编号
				if (Vexset[j] == vs2) Vexset[j] = vs1;//集合编号为vs2的都改成vs1
			}
		}
	}
}
int main() {
	AMGraph G;
	CreateUDN(G);
	MiniSpanTree_Kruskal(G);
	return 0;
}