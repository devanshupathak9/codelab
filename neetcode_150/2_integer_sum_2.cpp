// Given an array of integers numbers that is sorted in non-decreasing order.

// Return the indices (1-indexed) of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2. Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.

// There will always be exactly one valid solution.

// Your solution must use 
// O(1) additional space

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) return {i + 1, j + 1};
            if (sum > target) j-=1;
            if (sum < target) i+=1;
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    int target = 3;
    Solution sol;
    vector<int> res = sol.twoSum(nums, target);
    cout << res[0] << " " << res[1] << "\n";
    return 0;
}