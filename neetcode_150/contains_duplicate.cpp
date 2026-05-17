// Contains Duplicate
// Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

class Solution {
public:
    bool hasDuplicate(vector<int> &nums) {
        unordered_map<int, int> umap;
        for (auto it : nums) {
            if (umap.find(it) != umap.end()) {
                return true;
            }
            umap[it]++;
        }
        return false;
    }
};

int main() {
    vector<int> vec = {1, 2, 2, 3};
    Solution sol;
    bool answer = sol.hasDuplicate(vec);
    print(answer);
    return 0;
}