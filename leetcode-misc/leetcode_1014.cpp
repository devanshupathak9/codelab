// 1014. Best Sightseeing Pair

// You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
// The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
// Return the maximum score of a pair of sightseeing spots. 

#include <iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int maxScoreSightseeingPair(vector<int> &values) {
        int maxSum = 0;
        vector<int>maxSumVec;
        for (int i = 0; i<values.size(); i++) {
            maxSum = max(maxSum, values[i] + i);
            maxSumVec.push_back(maxSum);
        }
        int diff = 0, maxVal = 0;
        for (int i = 1; i<values.size(); i++) {
            diff = values[i] - i;
            maxVal = max(maxVal, diff + maxSumVec[i-1]);
        }
        return maxVal;
    }
};

int main() {
    vector <int> values = {8, 1, 5, 2, 6};
    Solution sol;
    cout <<sol.maxScoreSightseeingPair(values) << "\n";

}