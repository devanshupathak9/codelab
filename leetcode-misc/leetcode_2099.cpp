// 2099
// Find Subsequence of Length K With the Largest Sum
// You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
// Return any such subsequence as an integer array of length k.
// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


// Solution: The solution uses a max-heap (priority queue) to efficiently select the k largest elements from the input array, 
// while keeping track of their original indices. Each element is pushed into the heap as a pair of its value and index. 
// The top k elements are then popped from the heap and stored along with their original indices. 
// To maintain the original order of the subsequence, the selected pairs are sorted by their indices. 
// Finally, the values are extracted in order and returned as the subsequence with the largest sum.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        vector<int> answer;
        vector<pair<int ,int>> res;
        priority_queue<pair<int ,int>>pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(make_pair(nums.at(i), i));
        }
        while (k) {
            pair<int ,int>p = pq.top(); pq.pop();
            res.push_back({p.second, p.first});
            k--;
        }
        sort(res.begin(), res.end());

        for(int i = 0; i < res.size(); i++) {
            answer.push_back(res[i].second);
        }
        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,-2,3,4};
    int k = 3;
    vector<int> res = sol.maxSubsequence(nums, k);
    for (int num: res) { cout << num << " "; }
    return 0;
}