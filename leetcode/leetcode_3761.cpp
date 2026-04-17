// 3761. Minimum Absolute Distance Between Mirror Pairs
// A mirror pair is a pair of indices (i, j) such that:

// 0 <= i < j < nums.length, and
// reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. Leading zeros are omitted after reversing, for example reverse(120) = 21.
// Return the minimum absolute distance between the indices of any mirror pair. The absolute distance between indices i and j is abs(i - j).

// If no mirror pair exists, return -1.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
typedef long long ll;

template <typename T>
void print(T value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T> value) {
    for(auto val: value) {
        cout << val << " ";
    }
    print("");
}

class Solution {
public:
    string reverseNum(int num) {
        string rev;
        int rem, q;
        int flag = 1;
        while (num)
        {
            rem = num%10;
            num = num/10;
            if (rem == 0 && flag) {
                continue;
            } else {
                flag = 0;
                rev += rem + '0';
            }
        }
        return rev;
    }

    int findIndex(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int idx = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > target) {
                idx = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return idx;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int minDist = INT_MAX;
        int n = nums.size();
        unordered_map<string, vector<int>>umap;
        for(int i = 0; i < n; i++) {
            umap[to_string(nums[i])].push_back(i);
        }
        int idx;
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            string revnum = reverseNum(num);
            // print(num);
            // print(revnum);
            if (umap.find(revnum) != umap.end()) {
                vector<int> &indices = umap[revnum];
                // print_vector(indices);
                int idx = findIndex(indices, i);
                if (idx != -1 && indices[idx] > i) {
                    minDist = min(minDist, abs(indices[idx] - i));
                }
            }
            // print("===========================");
        }
        if (minDist == INT_MAX) return -1;
        return minDist;
    }
};

int main() {
    vector<int> nums = {12,21,45,33,54};
    Solution sol;
    int ans = sol.minMirrorPairDistance(nums);
    print(ans);
    return 0;
}