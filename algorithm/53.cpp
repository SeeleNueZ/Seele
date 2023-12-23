#include <iostream>
#include<algorithm>
#include <vector>
 
using namespace std;
 
const int N = 4;  // 城市数量
 
int g[N][N] = {
    {0, 30, 6, 4},
    {30, 0, 5, 10},
    {6, 5, 0, 20},
    {4, 10, 20, 0}
};
 
int minCost = INT_MAX;  // 最少花费
vector<int> path;  // 最优路径
 
// 回溯函数
void dfs(int u, int cost, vector<int>& p) {
    // 如果已经走完了所有城市，则更新最少花费和最优路径
    if (p.size() == N) {
        if (cost < minCost) {
            minCost = cost;
            path = p;
        }
        return;
    }
 
    // 遍历所有的城市
    for (int v = 1; v < N; v++) {
        // 如果当前城市没有走过，则继续搜索
        if (find(p.begin(), p.end(), v) == p.end()) {
            // 如果能到达该城市，则添加到路径中
            if (g[u][v] > 0) {
                p.push_back(v);
                dfs(v, cost + g[u][v], p);
                p.pop_back();
            }
        }
    }
}
 
int main() {
   
    vector<int> p;
    p.push_back(0);  // 从城市1出发
    dfs(0, 0, p);  // 开始回溯
 
    cout << "最少花费：" << minCost << endl;  // 输出最少花费
    cout << "最优路径：";
    for (int i = 0; i < path.size(); i++) {
        
        if (i == path.size() - 1) {
            cout << path[i] + 1 << endl;
        }
        else {
            cout << path[i] + 1 << "-> ";
        }
    }
    cout <<endl;
    
    return 0;
}
