#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::vector<int> stack;
    std::string line;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "PUSH") {
            int value;
            iss >> value;
            stack.push_back(value);
        } else if (command == "POP") {
            if (!stack.empty()) {
                int top = stack.back();
                std::cout << top << std::endl;
                stack.pop_back();
            } else {
                std::cout << "NULL" << std::endl;
            }
        } else {
            break;  // Exit on '#' or end of input
        }
    }

    return 0;
}

