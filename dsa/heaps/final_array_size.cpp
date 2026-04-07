// # Final size of the array after different elements cancels out each other
// {1, 2, 3, 3, 2, 2, 4, 4, 5}
// After cancelling different elements: final array size is 1;

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int FinalArraySize(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> element_count;
        priority_queue<pair<int, int>> counter;
        for (int it : nums)
            element_count[it]++;
        for (auto &pair : element_count)
        {
            counter.push(make_pair(pair.second, pair.first));
        }
        while (counter.size() > 1)
        {
            pair<int, int> top = counter.top();
            counter.pop();
            pair<int, int> top2 = counter.top();
            counter.pop();
            if (top.first - top2.first > 0){
                counter.push(make_pair(top.first - top2.first, top.second));
            }
        }
        if (counter.size() == 1)
            return counter.top().first;
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 4, 4, 4, 4};
    cout << sol.FinalArraySize(nums) << endl;
}