#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        return sum2;
    }
};
int main()
{
    Solution sol;
    vector<int> nums1 = {2, 2, 0, 4, 0};
    vector<int> nums2 = {6, 5, 0};
    cout << sol.minSum(nums1, nums2);
}