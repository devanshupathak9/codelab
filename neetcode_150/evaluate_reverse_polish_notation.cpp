// Evaluate Reverse Polish Notation
// You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.

// Return the integer that represents the evaluation of the expression.

// The operands may be integers or the results of other operations.
// The operators include '+', '-', '*', and '/'.
// Assume that division between integers always truncates toward zero.

// Example 1:
// Input: tokens = ["1","2","+","3","*","4","-"]
// Output: 5

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;


class Solution {
private:
    unordered_set<string> umap = {"+", "-", "*", "/"};
public:
    int evalRPN(vector<string>& tokens) {
        int res;
        int n = tokens.size();
        stack<string> stck;
        for (int i = 0; i < n; i++) {
            string token = tokens[i];
            if (umap.find(token) == umap.end()) stck.push(token);
            else {
                int top = stoi(stck.top()); stck.pop();
                int second = stoi(stck.top()); stck.pop();
                if (token == "+") {
                    res = second + top;
                } 
                else if (token == "-") {
                    res = second - top;
                } 
                else if (token == "*") {
                    res = second * top;
                } 
                else if (token == "/") {
                    res = second / top;
                }
                stck.push(to_string(res));
            }
        }
        return stoi(stck.top());
    }
};

int main() {
    vector<string> tokens = {"1","2","+","3","*","4","-"};
    Solution sol;
    cout << sol.evalRPN(tokens) << "\n";
    return 0;
}