// 1871. Jump Game VII
// You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

// i + minJump <= j <= min(i + maxJump, s.length - 1), and
// s[j] == '0'.
// Return true if you can reach index s.length - 1 in s, or false otherwise.

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

template <typename T>
void print(T &value)
{
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T> &value)
{
    for (auto it : value)
        cout << it << " ";
    print("");
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.size();
        if (s[n - 1] == '1')
            return false;
        vector<bool> dp(n, false);
        dp[0] = true;
        queue<int> q;
        q.push(0);
        while (q.size()) {
            int ind = q.front();
            int mn = ind + minJump;
            int mx = ind + maxJump;
            for (int i = mn; i < min(n-1, mx); i++) {
                if (s[i] == '0' && )
            }

        }
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '1') continue;
            for (int j = i - 1; j >= max(0, i - maxJump); j--)
            {
                if (s[j] == '0' && i >= j + minJump && i <= j + maxJump)
                {
                    print(i);
                    print(s[i]);
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        if (dp[n-1] == INT16_MAX) return false;
        return true;
    }
};

int main()
{
    string s = "011010";
    int minJump = 2, maxJump = 3;
    Solution sol;
    bool answer = sol.canReach(s, minJump, maxJump);
    print(answer);
    return 0;
}