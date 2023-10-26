#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n < 2 || n >31) {
        std::cout << "Invalid input." << std::endl;
        return 1; // Exit with an error code
    }

    long long fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    std::cout << fib[n - 1] << std::endl;

    return 0; // Exit successfully
}

