// 1846. Maximum Element After Decreasing and Rearranging
// You are given an array of positive integers arr. Perform some operations (possibly none) on arr so that it satisfies these conditions:

// The value of the first element in arr must be 1.
// The absolute difference between any 2 adjacent elements must be less than or equal to 1. In other words, abs(arr[i] - arr[i - 1]) <= 1 for each i where 1 <= i < arr.length (0-indexed). abs(x) is the absolute value of x.
// There are 2 types of operations that you can perform any number of times:

// Decrease the value of any element of arr to a smaller positive integer.
// Rearrange the elements of arr to be in any order.
// Return the maximum possible value of an element in arr after performing the operations to satisfy the conditions.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxElement = 1;
        int prev = 1;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (i == 0) prev = 1;
            else {
                if (abs(prev - num) > 1) {
                    prev = prev + 1;
                } else {
                    prev = num;
                }
            }
            maxElement = max(maxElement, prev);
        }
        return maxElement;
    }
};

int main() {
    vector<int> arr = {1,2,1,4,6,3,2,3,2,6,7,8};
    Solution sol;
    cout << sol.maximumElementAfterDecrementingAndRearranging(arr) << "\n";
    return 0;
}