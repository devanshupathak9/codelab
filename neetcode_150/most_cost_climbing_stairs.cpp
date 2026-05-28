// Min Cost Climbing Stairs
// You are given an array of integers cost where cost[i] is the cost of taking a step from the ith floor of a staircase. After paying the cost, you can step to either the (i + 1)th floor or the (i + 2)th floor.

// You may choose to start at the index 0 or the index 1 floor.

// Return the minimum cost to reach the top of the staircase, i.e. just past the last index in cost.


#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T> &value) {
    for(auto val: value) cout << val << " ";
    print("");
}


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
};

int main() {
    vector<int>cost = {1,2,1,2,1,1,1};
    Solution sol;
    int res = sol.minCostClimbingStairs(cost);
    print(res);
    return 0;
}