// 2044. Count Number of Maximum Bitwise-OR Subsets
// Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.
// An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.
// The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> count;
        int max_bitwise_or = 0;

        for (int i = 1; i < (1 << n); i++) {
            int bitwise_or = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    bitwise_or = bitwise_or | nums[j];
                }
            }
            max_bitwise_or = max(max_bitwise_or, bitwise_or);
            count[bitwise_or] += 1;
        }
        return count[max_bitwise_or];
    }
};

int main()
{
    vector<int> vec = {3, 2, 1, 5};
    Solution sol;
    cout << sol.countMaxOrSubsets(vec) << endl;
}