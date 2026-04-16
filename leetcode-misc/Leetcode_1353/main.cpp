// 1353. Maximum Number of Events That Can Be Attended

// You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
// You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.
// Return the maximum number of events you can attend.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        int maxevent = 0, count = 0;
        stack<pair<int, int>> stck;
        int size = events.size();
        if (size <= 1) return size;
        sort(events.begin(), events.end(), [](const vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        stck.push({events[0][0], events[0][1]});
        for (int i = 1; i < size; i++){
            vector<int> event = events[i];
            if (event[0] > stck.top().second){
                maxevent += min(count, stck.top().second - stck.top().first + 1);
                count = 1;
                stck.push(make_pair(event[0], event[1]));
            }
            else {
                count += 1;
                if (event[1] > stck.top().second && event[0] <= stck.top().second){

                }
                else if 

            }
        }
        return 5;
    }
};

int main()
{
    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
    Solution sol;
    auto res = sol.maxEvents(events);
    cout << res << endl;
}