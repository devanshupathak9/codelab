// 1855. Maximum Distance Between a Pair of Values
// You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.
// A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.
// Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.
// An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void print(T value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T>value) {
    for(auto val: value) {
        cout << value << " ";
    }
    print("");
}

class Solution {
public:
    int findIndex(int target, vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int res = -1;
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (target > nums[mid]) {
                end = mid - 1;
            } else {
                res = mid;
                start = mid + 1;
            }
        }
        return res;
    }
    
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int idx;
        int maxDist = 0;
        for(int i = 0; i < nums1.size(); i++) {
            idx = findIndex(nums1[i], nums2);
            if (idx!= -1 && idx >= i) {
                maxDist = max(maxDist, idx - i);
            }
        }
        return maxDist;
    }
};

int main() {
    // vector<int> nums1 = {55,30,5,4,2};
    // vector<int> nums2 = {100,20,10,10,5};

    vector<int> nums1 = {30,29,19,5};
    vector<int> nums2 = {25,25,25,25,25};
    Solution sol;
    int ans = sol.maxDistance(nums1, nums2);
    print(ans);
    return 0;
}