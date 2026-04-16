// 2154. Keep Multiplying Found Values by Two
// You are given an array of integers nums. You are also given an integer original which is the first number that needs to be searched for in nums.
// You then do the following steps:
// If original is found in nums, multiply it by two (i.e., set original = 2 * original).
// Otherwise, stop the process.
// Repeat this process with the new number as long as you keep finding the number.
// Return the final value of original.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int> &nums, int original) {
        unordered_map<int, bool> counter;
        for (int num : nums)
            counter[num] = true;
        while (counter.find(original) != counter.end()) {
            original = original*2;
        }
        return original;
    }
};

int main() {
    vector<int> nums = {2, 7, 4, 3, 16, 54, 8, 13, 6};
    int original = 3;
    Solution sol;
    cout << sol.findFinalValue(nums, original) << "\n";
}