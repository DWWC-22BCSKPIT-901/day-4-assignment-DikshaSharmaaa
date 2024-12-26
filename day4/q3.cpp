#include <stack>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TextEditor {
private:
    string currentString; // Stores the current state of the text
    stack<pair<int, string>> operations; // Stack to store operations for undo

public:
    /** Append a string to the current string. */
    void append(const string& w) {
        operations.push({1, w}); // Store the operation
        currentString += w;
    }

    /** Delete the last k characters from the current string. */
    void deleteLast(int k) {
        string deleted = currentString.substr(currentString.size() - k, k);
        operations.push({2, deleted}); // Store the operation
        currentString.erase(currentString.size() - k, k);
    }

    /** Print the k-th character of the current string. */
    char print(int k) {
        return currentString[k - 1]; // 1-based index
    }

    /** Undo the last operation. */
    void undo() {
        if (operations.empty()) return;
        auto lastOperation = operations.top();
        operations.pop();

        if (lastOperation.first == 1) {
            // Undo append
            currentString.erase(currentString.size() - lastOperation.second.size(), lastOperation.second.size());
        } else if (lastOperation.first == 2) {
            // Undo delete
            currentString += lastOperation.second;
        }
    }
};

int main() {
    TextEditor editor;
    int Q;
    cin >> Q;
    vector<string> results;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            string w;
            cin >> w;
            editor.append(w);
        } else if (type == 2) {
            int k;
            cin >> k;
            editor.deleteLast(k);
        } else if (type == 3) {
            int k;
            cin >> k;
            results.push_back(string(1, editor.print(k)));
        } else if (type == 4) {
            editor.undo();
        }
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
