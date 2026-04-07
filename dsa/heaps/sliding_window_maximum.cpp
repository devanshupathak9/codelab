// Leetcode 239. Sliding Window Maximum
// You are given an array of integers nums, there is a sliding window of size k which is moving
//  from the veryleft of the array to the very right. You can only see the k numbers in the window.
// Each time the sliding window moves right by one position.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> max_heap;
        vector<int> window_maximum;
        int beg = 0;
        for (int end = 0; end < nums.size(); end++)
        {
            max_heap.push(make_pair(nums[end], end));
            if (end >= k)
            {
                beg += 1;
            }
            while (max_heap.top().second < beg)
            {
                max_heap.pop();
            }
            if (end - beg + 1 == k)
                window_maximum.push_back(max_heap.top().first);
        }
        return window_maximum;
    }
};

int main()
{
    vector<int> nums = {1, 3, -1, 8, 2, -6, -7, -3, 5, 3, -6, 7};
    int k = 3;
    Solution sol;
    auto res = sol.maxSlidingWindow(nums, k);
    for (int it : res)
    {
        cout << it << " ";
    }
    cout << endl;
}