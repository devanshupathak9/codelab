// 724. Find Pivot Index
// Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.

// Example 1:

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prefix.push_back(sum);
        }

        bool flag = false;
        int index = n;
        int ssum = 0, prevValue = 0;
        for (int i = n-1; i >= 0; i--) {
            ssum += nums[i];
            int prefixValue = (i-1) >= 0? prefix[i-1]: 0;
            if (prevValue == prefixValue) {
                flag = true;
                index = i;
            }
            prevValue = ssum;
        }
        if (flag) return index;
        return -1;  
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << sol.pivotIndex(nums) << endl;

    return 0;
}
