// 3719. Longest Balanced Subarray I
// You are given an integer array nums.
// A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.

// Return the length of the longest balanced subarray.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
public:
    int longestBalanced(vector<int>& nums) {
        unordered_map<int, int>umap;
        for(auto it: nums) {
            if (it&1 && umap.find(it) == umap.end()){
                count_odd += 1;
                umap[it] = 1;
            } else if (it%2 == 0 && umap.find(it) == umap.end()){
                count_even += 1;
                umap[it] = 1;
            }
        }

    }
};

template <Typename T> void print(T value) {
    cout << value << "\n";
}

int main() {
    Solution sol;
    vector<int>vec = {3, 2, 2, 5, 4};
    int res = sol.longestBalanced(vec);
    print(res);
    return 0;
}
