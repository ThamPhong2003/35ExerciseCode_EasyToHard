#include <iostream>
#include <vector>

using namespace std;

void generateCollections(int n, int M, vector<int>& current, int index) {
    if (index == n) {
        if (M == 0) {
            // Print the collection
            for (int i = 0; i < n; i++) {
                cout << current[i];
                 cout << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = 1; i <= M; i++) {
        current[index] = i;
        generateCollections(n, M - i, current, index + 1);
    }
}

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> current(n);
    generateCollections(n, M, current, 0);

    return 0;
}

