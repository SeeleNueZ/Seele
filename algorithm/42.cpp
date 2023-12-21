//【贪心算法】单源最短路径问题
#include <iostream>
using namespace std;

#define N 5		// 5个顶点，1、2、3、4、5
#define M 9999	// maxint，大整数

void Dijkstra(int n, int v, int dist[], int prev[], int c[][N + 1]);
void Traceback(int v, int i, int prev[]);

int main()
{
	int v = 1;			// 源点为1
	int dist[N + 1];	// 从源到顶点i的最短特殊路径长度
	int	prev[N + 1];	// 从源到顶点i的最短路径上前一个顶点
	// 带权有向图的邻接矩阵，行和列下标从1开始
	int c[N + 1][N + 1] = {
		{M,	M,	M,	M,	M,	M	},
		{M,	M,	10,	M,	30,	100	},
		{M,	M,	M,	50,	M,	M	},
		{M,	M,	M,	M,	M,	10	},
		{M,	M,	M,	20,	M,	60	},
		{M,	M,	M,	M,	M,	M	},
	};

	// “输入”：带权有向图
	cout << "带权有向图的邻接矩阵为：\n";
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << c[i][j] << "\t";
		cout << endl;
	}

	// Dijkstra算法
	Dijkstra(N, v, dist, prev, c);

	// 输出
	cout << "源点1到顶点5的最短路径长度为：" << dist[5];
	cout << "，路径为：";
	Traceback(1, 5, prev);
	cout << endl;

	return 0;
}


void Dijkstra(int n, int v, int dist[], int prev[], int c[][N + 1])
{
	bool s[N + 1];	// 顶点集合s
	for (int i = 1; i <= n; i++)
	{
		dist[i] = c[v][i];	// 从源到顶点i的最短特殊路径长度
		s[i] = false;

		if (dist[i] == M)
			prev[i] = 0;	// 从源到顶点i的最短路径上前一个顶点
		else
			prev[i] = v;
	}

	dist[v] = 0;
	s[v] = true;

	for (int i = 1; i < n; i++)
	{
		int temp = M;		// 
		int u = v;			// 上一顶点

		// 找到具有最短特殊路长度的顶点u
		for (int j = 1; j <= n; j++)
		{
			if ((!s[j]) && (dist[j] < temp))
			{
				u = j;
				temp = dist[j];
			}
		}
		s[u] = true;

		// 更新dist值
		for (int j = 1; j <= n; j++)
		{
			if ((!s[j]) && (c[u][j] < M))
			{
				int newdist = dist[u] + c[u][j];
				if (newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
	}
}

//输出最短路径 v源点，i终点，
void Traceback(int v, int i, int prev[])
{
	// 源点等于终点时，即找出全部路径
	if (v == i)
	{
		cout << i;
		return;
	}
	Traceback(v, prev[i], prev);
	cout << "->" << i;
}