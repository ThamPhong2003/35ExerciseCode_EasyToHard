#include <iostream>
#include <queue>
#include <string>
#include <sstream>

int main() {
    std::queue<int> q;
    std::string line;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "PUSH") {
            int value;
            iss >> value;
            q.push(value);
        } else if (command == "POP") {
            if (!q.empty()) {
                int front = q.front();
                std::cout << front << std::endl;
                q.pop();
            } else {
                std::cout << "NULL" << std::endl;
            }
        } else {
            break;  // Exit on '#' or end of input
        }
    }

    return 0;
}

