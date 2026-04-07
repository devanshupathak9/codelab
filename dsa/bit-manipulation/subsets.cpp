// 78. Subsets
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.
// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// /**
//  * @class Solution
//  * @brief Generates all possible subsets (the power set) of a given vector of integers.
//  *
//  * The approach uses bit manipulation to enumerate all possible combinations.
//  * For each integer from 0 to 2^n - 1 (where n is the size of the input vector),
//  * the bits of the integer represent whether to include each element in the subset.
//  * If the j-th bit is set, nums[j] is included in the current subset.
//  * This method efficiently generates all subsets without recursion.
//  *
//  * @param nums The input vector of integers.
//  * @return A vector containing all subsets of the input vector.
//  */

#include <iostream>
#include <vector>
using namespace std;


template <typename T>
void print(const T& value) {cout << value <<"\n";}


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for (int i = 0; i <= pow(2, nums.size()) - 1; i++) {
            vector<int> vect;
            for (int j = 0; j < nums.size(); j++) {
                if (i&(1<<j)) {
                    vect.push_back(nums[j]);
                }
            }
            res.push_back(vect);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = sol.subsets(nums);
    for (int i = 0; i < res.size(); i++) {
        for (auto it: res[i]) {
            cout << it << " ";
        }
        cout << "\n";
    }
}