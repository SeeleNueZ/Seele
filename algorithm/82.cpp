#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#define MAX 100010
#define INF 0x3f3f3f3f

int h[MAX];//用于存储每一个顶点最后连接的是哪一个顶点;
int num = 0;//用于记录边的数量，记住，每一对平行边的序号一定相邻;
int s,t;
int p[105][105];//用于记录两点的相邻与否；

struct node{
    int from;//该边的始点
    int to;//该边的终点
    int weight;//该边的权值
    int next;//该边始点下一个连接的边
}Edge[MAX];

int Min(int a, int b)
{
    return a < b ? a : b;
}

void AddEdge(int f, int t, int w)
{
    Edge[++num].from = f;
    Edge[num].to = t;
    Edge[num].weight = w;
    Edge[num].next = h[f];//第一个存储的next值就取0，以便于后面判定是否已经把这个点相邻的点找完（行45，行66）
    h[f] = num;//用于下一次再有以f为始点的边记录
}

int d[MAX];//用于记录到起点的距离，也可以当做在遍历时判定上一个点是否已经走过了的条件
bool BFS()
{
    memset(d,0,sizeof(d));//每一次重新找剩余网络都需要更新d数组;
    d[s] = 1;//其实在一般情况下，这里的起始点的d值应该为0才说得过去，但由于后面判定这个点是否已经走过是由d[i]是否为0来判定的，所以我们起始点用1
    std::queue<int> Q;
    Q.push(s);
    while(!Q.empty())
    {
        int q = Q.front();
        Q.pop();
        for(int i = h[q]; i != 0; i = Edge[i].next)
        {
            int to = Edge[i].to;
            if(d[to] == 0 && Edge[i].weight != 0)
            {
                d[to] = d[q] + 1;
                if(to == t)
                {
                    for(int j = s; j <= t; j ++)
                        printf("%d ", d[j]);
                    printf("\n");
                    return true;
                }
                Q.push(to);
            }
        }
    }
    return d[t] != 0;
}

int DFS(int from, int flow)//from是当前进行遍历的点的编号，flow是当前流进from点的流量;
{
    if(from == t)
        return flow;
    int sum = 0;//sum用来记录这一点from到底能够流多少流量;
    int r = flow;//r在接下来用于记录这一点from流了一定的流量之后，还剩下多少流量可流出;
    for(int i = h[from]; i && r; i = Edge[i].next)
    {
        int to = Edge[i].to;
        if(d[to] == d[from] + 1 && Edge[i].weight != 0)
        {
            int key = DFS(to, Min(r, Edge[i].weight));//递归找到以这个点为起点能流过多少流量，流进的流量为r和权值的最小值;
            if(key == 0)
                d[to] = 0;//如果以这个点起不能再流进，那么这个点作废;
            Edge[i].weight -= key;
            Edge[i + 1].weight += key;//[i + 1]就是边[i]的平行边;
            r -= key;
            sum += key;
        }
    }
    return sum;
}

int main()
{
    int N,i;
    scanf("%d", &N);//点的总数;
    s = 1;
    t = N;
    int a, b, c;
    memset(h, 0, sizeof(h));
    memset(p, 0, sizeof(p));
    while(scanf("%d%d%d", &a, &b, &c) != EOF)
    {
        if(p[a][b] == 0)
        {
            AddEdge(a,b,c);
            p[a][b] = num;
            AddEdge(b,a,0);
            p[b][a] = num;
        }
        else 
        {
            Edge[p[a][b]].weight += c;
        }
    }
    // for(i = 1; i <= num; i++)
    //     printf("from = %d to = %d weight = %d next = %d\n", Edge[i].from, Edge[i].to, Edge[i].weight, Edge[i].next);
    int ans = 0;
    while(BFS())
    {
        ans += DFS(s, INF);
        printf("%d\n", ans);
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
    /*
    https://blog.csdn.net/qq_43764726/article/details/105705300
11
1 2 7
1 3 8
1 4 9
1 5 10
1 6 11
2 3 2
2 7 5
3 4 3
3 7 2
3 8 5
4 5 4
4 8 3
4 9 6
5 6 5
5 9 4
5 10 6
6 10 20
7 11 13
8 7 4
8 11 12
9 8 3
9 11 11
10 9 2
10 11 10
然后打一个ctrl+Z
    */
}