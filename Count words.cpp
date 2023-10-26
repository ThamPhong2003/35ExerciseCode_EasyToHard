#include <iostream>
using namespace std;

int main() {
    string line;
    int totalWordCount = 0;

    // Keep reading lines until the end of input
    while (getline(cin, line)) {
        int wordCount = 0;
        bool inWord = false;
        for (char c : line) {
            if (c != ' ' && c != '\t' && c != '\n') {
                if (!inWord) {
                    inWord = true;
                    wordCount++;
                }
            } else {
                inWord = false;
            }
        }

        totalWordCount += wordCount;
    }

    cout  << totalWordCount << endl;

    return 0;
}

