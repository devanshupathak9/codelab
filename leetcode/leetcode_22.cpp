// 22. Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> res;
public:
    void generateValidParenthesis(int o, int c, vector<char> &p) {
        if (o > c) return;
        if (o ==0 && c == 0) {
            string str(p.begin(), p.end());
            res.push_back(str);
            return;
        }
        if (o > 0) {
            p.push_back('(');
            generateValidParenthesis(o-1, c, p);
            p.pop_back();
        }
        if (c > 0) {
            p.push_back(')');
            generateValidParenthesis(o, c-1, p);
            p.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<char> p = {};
        generateValidParenthesis(n, n, p);
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> res = sol.generateParenthesis(3
    
    );
    for (auto str: res) cout << str << " ";
    cout << "\n";
    return 0; 
}