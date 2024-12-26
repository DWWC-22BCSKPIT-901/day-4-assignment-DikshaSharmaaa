#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
private:
    stack<int> stack1; // Used for push operations
    stack<int> stack2; // Used for pop and peek operations

    // Transfers elements from stack1 to stack2 if stack2 is empty
    void transferIfNeeded() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }

public:
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        transferIfNeeded();
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    /** Get the front element. */
    int peek() {
        transferIfNeeded();
        return stack2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    MyQueue myQueue;

    myQueue.push(1);
    myQueue.push(2);
    cout << myQueue.peek() << endl; // Returns 1
    cout << myQueue.pop() << endl;  // Returns 1
    cout << myQueue.empty() << endl; // Returns false

    return 0;
}
