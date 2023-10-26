#include <iostream>
#include <string>
using namespace std;

// Function to generate binary sequences of length n
void generateBinarySequences(int n, string sequence = "") {
    // If the sequence has reached the desired length, print it
    if (sequence.length() == n) {
        cout << sequence << endl;
        return;
    }

    // Append '0' and '1' to the sequence and recurse
    generateBinarySequences(n, sequence + '0');
    generateBinarySequences(n, sequence + '1');
}

int main() {
    int n;
    cin >> n;

    // Start generating binary sequences
    generateBinarySequences(n);

    return 0;
}

