#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0); // Frequency array for 26 lowercase letters

        // Count the frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Find the first character with a frequency of 1
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1; // No unique character found
    }
};

// Example usage
int main() {
    Solution solution;

    string s1 = "leetcode";
    cout << "First unique character in '" << s1 << "' is at index: " << solution.firstUniqChar(s1) << endl;

    string s2 = "loveleetcode";
    cout << "First unique character in '" << s2 << "' is at index: " << solution.firstUniqChar(s2) << endl;

    string s3 = "aabb";
    cout << "First unique character in '" << s3 << "' is at index: " << solution.firstUniqChar(s3) << endl;

    return 0;
}
