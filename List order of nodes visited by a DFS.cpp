#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& result, int node) {
    visited[node] = true;
    result.push_back(node);
    vector<int> neighbors = graph[node];
    sort(neighbors.begin(), neighbors.end());  // Sort neighbors in lexicographic order

    for (int neighbor : neighbors) {
        if (!visited[neighbor]) {
            dfs(graph, visited, result, neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    vector<int> result;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(graph, visited, result, i);
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

