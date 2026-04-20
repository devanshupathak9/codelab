// 2078. Two Furthest Houses With Different Colors
// There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.

// Return the maximum distance between two houses with different colors.

// The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(T value) {
    cout << value << "\n";
}

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDistance = 0;
        int n = colors.size();
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j <= i - 1; j++) {
                cout << colors[i] << " " << colors[j] <<"\n";
                if (colors[i] != colors[j]) {
                    maxDistance = max(maxDistance, abs(j - i));
                    break;
                }
            }
        }
        return maxDistance;
    }
};

int main() {
    vector<int>colors1 = {1,1,1,6,1,1,1};
    vector<int>colors2 = {1,8,3,8,3};
    vector<int>colors3 = {0,1};
    Solution sol;
    print(sol.maxDistance(colors3));
    return 0;
}