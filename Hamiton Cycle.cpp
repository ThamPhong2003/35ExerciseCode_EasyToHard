#include <iostream>
#include <vector>
using namespace std;

bool is_hamiltonian(vector<vector<int>>& graph, vector<int>& path, vector<bool>& visited, int pos, int n) {
    if (pos == n) {
        // Check if there is an edge from the last vertex to the first vertex
        if (graph[path[n - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < n; v++) {
        if (!visited[v] && graph[path[pos - 1]][v] == 1) {
            path[pos] = v;
            visited[v] = true;
            if (is_hamiltonian(graph, path, visited, pos + 1, n))
                return true;
            path[pos] = -1;
            visited[v] = false;
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    vector<int> results;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u - 1][v - 1] = 1;
            graph[v - 1][u - 1] = 1;
        }

        vector<int> path(n, -1);
        vector<bool> visited(n, false);

        int result = 0;
        for (int i = 0; i < n; i++) {
            path[0] = i;
            visited[i] = true;
            if (is_hamiltonian(graph, path, visited, 1, n)) {
                result = 1;
                break;
            }
            visited[i] = false;
        }

        results.push_back(result);
    }

    for (int i = 0; i < T; i++) {
        cout << results[i] << endl;
    }

    return 0;
}

