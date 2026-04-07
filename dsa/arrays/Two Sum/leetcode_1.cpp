// 1. Two Sum
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
void println(T value) { cout << value << "\n"; }

template <typename T>
void print(T value) { cout << value << " "; }

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mapper;
        for(int i = 0; i < nums.size(); i++) {
            if (mapper.find(target - nums[i]) != mapper.end()) {
                    return {i, mapper[target - nums[i]]};
            }
            mapper[nums[i]] = i;;
        }
        throw invalid_argument("No indexes found!!");
    }
};

int main() {
    Solution sol;
    vector<int> vect = {11, 2, 7, 5};
    int target = 9;

    vector<int> res = sol.twoSum(vect, target);
    for (auto it: res) print(it);
    println(" ");
    return 0;
}