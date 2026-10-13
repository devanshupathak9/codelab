// 2390. Removing Stars From a String

// You are given a string s, which contains stars *.
// In one operation, you can:

// Choose a star in s.
// Remove the closest non-star character to its left, as well as remove the star itself.
// Return the string after all stars have been removed.

// Note:
// The input will be generated such that the operation is always possible.
// It can be shown that the resulting string will always be unique.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        for(auto ch: s) {
            if (ch == '*') {
                stk.pop(); continue;
            } 
            stk.push(ch);
        }
        string newStr = "";
        while (!stk.empty()) {
            newStr += stk.top(); stk.pop();
        }
        reverse(newStr.begin(), newStr.end());
        return newStr;
    }
};


int main() {
    Solution sol;
    string s = "leet**cod*e";
    cout << sol.removeStars(s) << endl;

    return 0;
}