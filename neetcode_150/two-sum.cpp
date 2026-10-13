// Two Sum
// Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.
// You may assume that every input has exactly one pair of indices i and j that satisfy the condition.
// Return the answer with the smaller index first.

// Example 1:
// Input: 
// nums = [3,4,5,6], target = 7

// Output: [0,1]
// Explanation: nums[0] + nums[1] == 7, so we return [0, 1].

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (umap.find(target - num) != umap.end()) {
                return {umap[target - num], i};
            }
            umap[num] = i;
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 22;
    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << "\n";
}