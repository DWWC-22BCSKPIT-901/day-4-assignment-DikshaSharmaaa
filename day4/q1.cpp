#include <stack>
#include <iostream>
using namespace std;

class MinStack {
private:
    stack<int> mainStack; // Stack to hold all elements
    stack<int> minStack;  // Stack to hold minimum elements

public:
    /** Initialize the stack. */
    MinStack() {
        // Constructor does nothing specific in this case
    }

    /** Push an element onto the stack. */
    void push(int val) {
        mainStack.push(val);
        // Push to minStack if it is empty or the new value is <= current minimum
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    /** Remove the top element of the stack. */
    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    /** Get the top element of the stack. */
    int top() {
        return mainStack.top();
    }

    /** Retrieve the minimum element in the stack. */
    int getMin() {
        return minStack.top();
    }
};

// Example usage
int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "getMin(): " << minStack.getMin() << endl; // Outputs: -3
    minStack.pop();
    cout << "top(): " << minStack.top() << endl;      // Outputs: 0
    cout << "getMin(): " << minStack.getMin() << endl; // Outputs: -2

    minStack.push(5);
    minStack.push(3);
    minStack.push(7);
    minStack.push(3);
    cout << "getMin(): " << minStack.getMin() << endl; // Outputs: 3
    minStack.pop();
    cout << "getMin(): " << minStack.getMin() << endl; // Outputs: 3
    cout << "top(): " << minStack.top() << endl;       // Outputs: 7
    cout << "getMin(): " << minStack.getMin() << endl; // Outputs: 3

    return 0;
}
