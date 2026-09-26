// 3524. Find X Value of Array I
// You are given an array of positive integers nums, and a positive integer k.

// You are allowed to perform an operation once on nums, where in each operation you can remove any non-overlapping prefix and suffix from nums such that nums remains non-empty.
// You need to find the x-value of nums, which is the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of x when divided by k.
// Return an array result of size k where result[x] is the x-value of nums for 0 <= x <= k - 1.
// A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.
// A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.
// Note that the prefix and suffix to be chosen for the operation can be empty.


#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(vector<T>& nums) {
    for (auto num: nums) cout << num << " ";
    cout << "\n";
}

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        int p = 1;
        vector<long long> prefix;
        for (int i = 0; i < n; i++) {
            p = p*nums[i];
            prefix.push_back(p);
        }
        long long x;
        vector<long long> umap(k, 0);
        for (int i = 0; i < n; i++) {
            for (int j = -1; j < i; j++) {
                if (j == -1) {
                    x = prefix[i];
                } else {
                    x = prefix[i]/prefix[j];
                }
                x = x%k;
                umap[x]++;
            }
        }
        return umap;
    }
};

int main() {
    vector<int> nums = {2,8,8,10,10,10,6,6,7,6,5,10,8,4,9,8};
    int k = 5;

    Solution sol;
    vector<long long>  res = sol.resultArray(nums, k);
    printVector(res);
    return 0;
}