// 594. Longest Harmonious Subsequence

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> counter;
        int max_subsequence = 0;
        for (int num : nums)
            counter[num]++;
        for (const auto &pair : counter)
        {
            if (counter.find(pair.first + 1) != counter.end())
            {
                max_subsequence = max(max_subsequence, counter[pair.first] + counter[pair.first + 1]);
            }
        }
        return max_subsequence;
    }
};
int main()
{
    vector<int> array = {3, 2, 2, 3, 6, 8, 2, 3};
    Solution sol;
    auto res = sol.findLHS(array);
    cout << res << endl;
}