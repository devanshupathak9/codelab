// 3660. Jump Game IX
// You are given an integer array nums.

// From any index i, you can jump to another index j under the following rules:

// Jump to index j where j > i is allowed only if nums[j] < nums[i].
// Jump to index j where j < i is allowed only if nums[j] > nums[i].
// For each index i, find the maximum value in nums that can be reached by following any sequence of valid jumps starting at i.

// Return an array ans where ans[i] is the maximum value reachable starting from index i.

#include <iostream>
#include <vector>
#include <queue>
#include <queue>
using namespace std;

template <typename T>
void print(T value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T> &value) {
    for(auto it: value) cout << it << " ";
    print("");
}


class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        int maxInd = 0;
        vector<int> suf;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[maxInd]) {
                maxInd = i;
            }
            suf.push_back(maxInd);
            cout << nums[maxInd] << " ";
        }
        print("");
        print_vector(suf);
        vector<int> prefix;
        for (int i = 0; i < n; i++) {
            int flag = 1;
            for (int j = n-1; j > i; j--) {
                if (nums[j] < nums[i]) {
                    flag = 0;
                    prefix.push_back(j);
                    break;
                }
            }
            if (flag) prefix.push_back(i);
            cout << nums[prefix[i]] << " ";
        }
        print("");
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = max(nums[suf[prefix[i]]], dp[suf[i]]);
        }
        print_vector(prefix);
        return dp;
    }
};


int main()
{
    vector<int>nums = {12, 5, 18, 3, 15, 7, 20, 1, 14, 9, 25, 6, 17, 2, 30, 60, 80};
    Solution sol;
    vector<int> result = sol.maxValue(nums);
    print_vector(result);
    return 0;
}