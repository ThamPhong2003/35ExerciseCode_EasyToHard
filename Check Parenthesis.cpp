#include <iostream>
#include <stack>
#include <string>

bool isCorrectExpression(const std::string& str) {
    std::stack<char> stack;

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.empty()) {
                return false;
            }

            char open = stack.top();
            stack.pop();

            if ((c == ')' && open != '(') || (c == ']' && open != '[') || (c == '}' && open != '{')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    std::string expression;
    std::cin >> expression;

    if (isCorrectExpression(expression)) {
        std::cout << "1" << std::endl;
    } else {
        std::cout << "0" << std::endl;
    }

    return 0;
}

