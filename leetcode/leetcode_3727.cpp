// 3727. Maximum Alternating Sum of Squares

// You are given an integer array nums. You may rearrange the elements in any order.
// The alternating score of an array arr is defined as:
// score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
// Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.

// Example 1:
// Input: nums = [1,2,3]
// Output: 12
// Explanation:
// A possible rearrangement for nums is [2,1,3], which gives the maximum alternating score among all possible rearrangements.
// The alternating score is calculated as:
// score = 22 - 12 + 32 = 4 - 1 + 9 = 12


#include <iostream>
#include <vector>
using namespace std;
#define ll long long

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) nums[i] *= nums[i];
        sort(nums.begin(), nums.end());
        ll res = 0;
        for (int i = 0; i < n/2; i++) {
            res += nums[n - 1 -i] - nums[i];
        }
        if (n&1) res += nums[n/2];
        return res;
    }
};

int main() {
    vector<int> nums = {1,-1, 2,-2 , 3, -3};
    Solution sol;
    ll res = sol.maxAlternatingSum(nums);
    cout << res;
    return 0;
}

