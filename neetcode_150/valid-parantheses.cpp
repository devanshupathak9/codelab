// Valid Parentheses
// You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

// The input string s is valid if and only if:

// Every open bracket is closed by the same type of close bracket.
// Open brackets are closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
// Return true if s is a valid string, and false otherwise.

// Example 1:
// Input: s = "[]"
// Output: true

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<char, char> umap {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };
public:
    bool isValid(string s) {
        stack<char> stck;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch =='(' || ch=='{' || ch =='[') {
                stck.push(ch);
            }
            else {
                if (stck.empty()) return false;
                char top = stck.top(); stck.pop();
                if (umap[ch] != top) return false;
            }
        }
        if (stck.size()) return false;
        return true;
    }
};

int main() {
    Solution sol;
    string s = "([{}])";
    bool ans = sol.isValid(s);
    cout << ans << "\n";
    return 0;
}