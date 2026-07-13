// 1288. Remove Covered Intervals
// Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
// The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
// Return the number of remaining intervals.

// Example 1:

// Input: intervals = [[1,4],[3,6],[2,8]]
// Output: 2
// Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
// Example 2:

// Input: intervals = [[1,4],[2,3]]
// Output: 1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        stack<pair<int, int>> stck;
        stck.push({intervals[0][0], intervals[0][1]});
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>interval = intervals[i];
            int start = interval[0], end = interval[1];
            pair<int, int> p = stck.top();
            if (end > p.second) {
                stck.push({start, end});
            }
        }

        return stck.size();
    }
};


int main() {
    Solution sol;
    vector<vector<int>> interval = {{1, 4}, {3, 6}, {2, 8}};
    int ans = sol.removeCoveredIntervals(interval);
    cout << ans << "\n";
}