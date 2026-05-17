// Two Sum

// Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.
// You may assume that every input has exactly one pair of indices i and j that satisfy the condition.
// Return the answer with the smaller index first.


#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T> &value) {
    for(auto it: value) {
        cout << it << " ";
    }
    print("");
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < n && j >= 0 && i<j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
            if (nums[i] + nums[j] > target) {
                j -= 1;
            } else {
                i += 1;
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums = {3,4,5,6};
    int target = 7;

    Solution sol;
    vector<int> answer = sol.twoSum(nums, target);
    print_vector(answer);
    return 0;
}
