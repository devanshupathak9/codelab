// 1536. Minimum Swaps to Arrange a Binary Grid
// Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
// A grid is said to be valid if all the cells above the main diagonal are zeros.
// Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
// The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
void print(T value) {
    cout << value << "\n";
}

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid)
    {
        vector<int>pos;
        int n = grid.size();
        int count = 0;
        int minSwaps = 0;
        for(int i = 0; i < n; i++) {
            int rightmost = -1;
            for(int j = n-1; j >=0; j--) {
                if (grid[i][j] == 1) {
                    rightmost = j;
                    break;
                } 
            }
            pos.push_back(rightmost);
        }

        for(int i = 0; i < n; i++) {
            int idx = -1;
            for (int j = i; j < n; j++) {
                if ( pos[j] <= i) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1) return -1;
            minSwaps += idx - i;
            for (int k = idx; k > 0; k--) {
                swap(pos[k], pos[k-1]);
            }

        }
        return minSwaps;
    }
};

int main() {
    vector<vector<int>>grid = {{0,0,1},{1,1,0},{1,0,0}};
    Solution sol;
    int res = sol.minSwaps(grid);
    print(res);
    return 0;
}