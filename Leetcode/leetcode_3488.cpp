// 3488. Closest Equal Element Queries
// You are given a circular array nums and an array queries.

// For each query i, you have to find the following:

// The minimum distance between the element at index queries[i] and any other index j in the circular array, where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1.
// Return an array answer of the same size as queries, where answer[i] represents the result for query i.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
void print(T& value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T>& value) {
    for(auto val: value) {
        cout << val << " ";
    }
    print("");
}

class Solution {
public:
    int findMinDist(int q, int prev, int next, int n) {
        int d1 = min((q - prev + n) % n, (prev - q + n) % n);
        int d2 = min((q - next + n) % n, (next - q + n) % n);
        return min(d1, d2);
    }
    int binarySearch(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (nums[mid] == target) return mid;
            if (target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> umap;
        for(int i = 0; i < nums.size(); i++) {
            umap[nums[i]].push_back(i);
        }
        vector<int> result;
        int idxn, currIndex, prev, next, minDist;
        for(auto idx: queries) {
            int num = nums[idx];
            vector<int> &indices = umap[num];
            if (indices.size() == 1) {
                result.push_back(-1);
                continue;
            }
            idxn = indices.size();
            currIndex = binarySearch(indices, idx);
            prev = indices[(currIndex + 1)%idxn];
            next = indices[(idxn + currIndex - 1)%idxn];
            minDist = findMinDist(idx, prev, next, n);
            result.push_back(minDist);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1, 3, 1, 4, 1, 3, 2};
    vector<int> queries = {0, 3, 5};
    Solution sol;
    vector<int> ans = sol.solveQueries(nums, queries);
    print_vector(ans);
    return 0;
}