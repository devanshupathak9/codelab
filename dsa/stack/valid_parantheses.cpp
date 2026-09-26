// 20. Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

#include <iostream>
#include <stack>
using namespace std;

class Solution {
private:
    unordered_map<char, char> umap = {
    {')', '('}, 
    {'}', '{'}, 
    {']', '['}
};
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stck;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '{' || ch == '[' || ch == '(') stck.push(ch);
            else {
                if (!stck.size()) return false;
                char top = stck.top(); 
                if (umap[ch] != top) return false;
                stck.pop();
            }
        }
        if (stck.size()) return false;
        return true;
    }
};

int main() {
    string s = "";
    Solution sol;
    bool ans = sol.isValid(s);
    cout << ans << "\n";
    return 0;
}