#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[100000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;
    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += a[i];
    }

    if (sum % 2 == 0) {
        count++;
    }

    for (int i = k; i < n; i++) {
        sum += a[i] - a[i - k];
        if (sum % 2 == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}

