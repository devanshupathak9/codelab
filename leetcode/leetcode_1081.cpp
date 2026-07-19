// 1081. Smallest Subsequence of Distinct Characters
// Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

// Example 1:

// Input: s = "bcabc"
// Output: "abc"
// Example 2:

// Input: s = "cbacdcbc"
// Output: "acdb"

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>last(26, 0);
        for (int i = 0; i <s.size(); i++) {
            char ch = s[i];
            last[ch - 'a'] = i;
        }
        stack<char> st;
        vector<bool>visited(26, false);

        for (int i = 0; i <s.size(); i++) {
            char ch = s[i];
            if (visited[ch - 'a']) continue;

            while (!st.empty() && 
                ch < st.top() && 
                last[st.top() - 'a'] > i
            ) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(ch);
            visited[ch - 'a'] = true;
        }
        string finalStr = "";
        while (!st.empty()) {
            finalStr += st.top();
            st.pop();
        }
        reverse(finalStr.begin(), finalStr.end());
        return finalStr;
    }
};


int main() {
    Solution sol;
    string s = "cadbadcba";
    string res = sol.smallestSubsequence(s);
    print(res);
    return 0;
}
