#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;

class RPNCalculator {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        // Define operations using lambdas
        unordered_map<string, function<int(int, int)>> operations = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}
        };

        for (const string& token : tokens) {
            if (operations.count(token)) {
                // It's an operator; pop two elements and apply the operation
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                stk.push(operations[token](a, b));
            } else {
                // It's an operand; push it onto the stack
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};

int main() {
    vector<string> tokens;
    int n;
    cout << "Enter the number of tokens: ";
    cin >> n;

    cout << "Enter the tokens separated by space (operands or operators): \n";
    for (int i = 0; i < n; ++i) {
        string token;
        cin >> token;
        tokens.push_back(token);
    }

    RPNCalculator calculator;
    int result = calculator.evalRPN(tokens);

    cout << "The result of the RPN expression is: " << result << endl;

    return 0;
}
