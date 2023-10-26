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
    generateBinarySequences(n, sequence + '0');
    
    if (sequence.length() == 0 || (sequence.length() > 0 && sequence[sequence.length() - 1] != '1')) {
        generateBinarySequences(n, sequence + '1');
    }
}

int main() {
    int n;
    cin >> n;

    // Start generating binary sequences
    generateBinarySequences(n);

    return 0;
}

