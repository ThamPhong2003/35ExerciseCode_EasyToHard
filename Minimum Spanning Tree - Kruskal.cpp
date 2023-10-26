#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;

// Structure to represent an edge
struct Edge {
    int v, w;
    Edge(int vertex, int weight) : v(vertex), w(weight) {}
};

vector<Edge> graph[MAXN];
bool visited[MAXN];

int prim(int n) {
    int minSpanTreeWeight = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 1}); // Start from vertex 1

    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        minSpanTreeWeight += weight;
        visited[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.v;
            int w = edge.w;
            if (!visited[v])
                pq.push({w, v});
        }
    }

    return minSpanTreeWeight;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    int minSpanTreeWeight = prim(N);

    cout << minSpanTreeWeight << endl;

    return 0;
}

