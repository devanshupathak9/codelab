// Valid Parentheses
// You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

// The input string s is valid if and only if:

// Every open bracket is closed by the same type of close bracket.
// Open brackets are closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
// Return true if s is a valid string, and false otherwise.


#include <iostream>
#include <stack>
using namespace std;


class Solution {
private:
    unordered_map<char, char> umap = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}
    };
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stck;
        for (char ch: s) {
            if (umap.find(ch) != umap.end()) stck.push(ch);
            else {
                if (!stck.size()) return false;
                char top = stck.top();
                if (umap[top] != ch) return false;
                stck.pop();
            }
        }
        if (stck.size()) return false;
        return true;
    }
};

int main() {
    string s = "([{}])(";
    Solution sol;
    bool ans = sol.isValid(s);
    cout << ans << "\n";
    return 0;
}