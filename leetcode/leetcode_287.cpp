// 287. Find the Duplicate Number
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and using only constant extra space.

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2

#include <iostream>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i] > n ? nums[i] - n: nums[i];
            if (nums[num] > n) return num;
            nums[num] += n;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 4, 4, 3};
    int res = sol.findDuplicate(nums);
    cout << res;
    return 0;
}