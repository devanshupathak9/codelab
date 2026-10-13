// 2333. Minimum Sum of Squared Difference
// You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.
// The sum of squared difference of arrays nums1 and nums2 is defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.

// You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by +1 or -1 at most k1 times. Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.
// Return the minimum sum of squared difference after modifying array nums1 at most k1 times and modifying array nums2 at most k2 times.
// Note: You are allowed to modify the array elements to become negative integers.

// Input: nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
// Output: 43
// Explanation: One way to obtain the minimum sum of square difference is: 
// - Increase nums1[0] once.
// - Increase nums2[2] once.
// The minimum of the sum of square difference will be: 
// (2 - 5)2 + (4 - 8)2 + (10 - 7)2 + (12 - 9)2 = 43.
// Note that, there are other ways to obtain the minimum of the sum of square difference, but there is no way to obtain a sum smaller than 43.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int diff, squaredDiff, minSum = 0;
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < nums1.size(); i++) {
            int diff = nums1[i] - nums2[i];
            int squaredDiff = diff * diff;
            minSum += squaredDiff;
            pq.push({squaredDiff, {nums1[i], nums2[i]}});
        }
        while (k1 != 0 || k2 != 0) {
            pair<int, pair<int, int>> curr = pq.top(); pq.pop();
            int a = curr.second.first;
            int b = curr.second.second;
            minSum -= curr.first;
            if (k1 > 0) {
                if (a > b) a -= 1;
                else if (a < b) a += 1;
                k1 -= 1;
            }
            if (k2 > 0) {
                if (a > b) b += 1;
                else if (a < b) b -= 1;
                k2 -= 1;
            }
            diff = a - b;
            squaredDiff = diff*diff;
            minSum += squaredDiff;
            pq.push({squaredDiff, {a, b}});
        }
        return minSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {2, 10, 20, 19};

    int k1 = 2;
    int k2 = 1;

    cout << sol.minSumSquareDiff(nums1, nums2, k1, k2) << endl;

    return 0;
}