#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int source, destination, weight;
    Edge(int s, int d, int w) : source(s), destination(d), weight(w) {}
};

class Graph {
public:
    int vertices;
    vector<Edge> edges;

    Graph(int V) : vertices(V) {}

    void addEdge(int u, int v, int w) {
        edges.emplace_back(u, v, w);
    }

    bool bellmanFord(int source, int target, vector<int>& dist) {
        dist[source] = 0;

        for (int i = 1; i < vertices; ++i) {
            for (const Edge& edge : edges) {
                if (dist[edge.source] != INT_MAX && dist[edge.source] + edge.weight < dist[edge.destination]) {
                    dist[edge.destination] = dist[edge.source] + edge.weight;
                }
            }
        }

        for (const Edge& edge : edges) {
            if (dist[edge.source] != INT_MAX && dist[edge.source] + edge.weight < dist[edge.destination]) {
                // 检测到负环
                return false;
            }
        }

        return true;
    }

    int findShortestPath(int source, int target) {
        vector<int> dist(vertices, INT_MAX);

        if (bellmanFord(source, target, dist)) {
            return (dist[target] == INT_MAX) ? -1 : dist[target];
        } else {
            cout << "图中存在负权边或负权环，无法找到最短路径。" << endl;
            return -1;  // 表示存在负权边或负权环
        }
    }
};

int main() {
    int vertices, edges;
    cout << "输入顶点数量: "; cin >> vertices;
    cout << "输入边的数量: "; cin >> edges;

    Graph g(vertices);

    cout << "输入边 (起点, 终点, 距离):\n";
    for (int i = 0, u, v, w; i < edges; ++i) {
        cout << "边 " << i + 1 << ": "; cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int source, target;
    cout << "输入起点顶点: "; cin >> source;
    cout << "输入终点顶点: "; cin >> target;

    int shortestPath = g.findShortestPath(source, target);

    if (shortestPath != -1) {
        cout << "从顶点 " << source << " 到 " << target << " 的最短路径: " << shortestPath << endl;
    }

    return 0;
}