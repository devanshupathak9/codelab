// 869. Reordered Power of 2
// You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
// Return true if and only if we can do this so that the resulting number is a power of two.

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> numcount(int n) {
        vector<int> count(10, 0);
        int rem;
        while (n) {
            rem = n % 10;
            count[rem] += 1;
            n = n / 10;
        }
        return count;
    }
    bool check(vector<int> a, vector<int> b) {
        for (int i = 0; i < 10; i++) {
            if (a[i]!=b[i])
                return false;
        }
        return true;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> basecase = numcount(n);
        for (int i = 0; i < 32; i++) {
            vector<int> res = numcount(pow(2, i));
            if (check(basecase, res))
                return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> testcase = {1, 2014, 36565, 6543250};
    for (int num : testcase)
    {
        cout << sol.reorderedPowerOf2(num) << "\n";
    }
    cout << endl;
}