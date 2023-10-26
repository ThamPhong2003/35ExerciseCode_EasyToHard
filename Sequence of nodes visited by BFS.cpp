#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& result, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        // Sort neighbors in lexicographic order
        vector<int> neighbors = graph[node];
        sort(neighbors.begin(), neighbors.end());

        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> result;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        // Sort initial edges in lexicographic order
        sort(graph[i].begin(), graph[i].end());
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(graph, visited, result, i);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}

