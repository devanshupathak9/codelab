// 1260. Shift 2D Grid
// Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

// In one shift operation:

// Element at grid[i][j] moves to grid[i][j + 1].
// Element at grid[i][n - 1] moves to grid[i + 1][0].
// Element at grid[m - 1][n - 1] moves to grid[0][0].
// Return the 2D grid after applying shift operation k times.

// Example 1:

// Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// Output: [[9,1,2],[3,4,5],[6,7,8]]

#include <iostream>
#include <vector>
using namespace std;

void print_matrix(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) { 
            cout << grid[i][j] << " ";
        } 
        cout << "\n";
    }
}

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));

        int r, c;
        int totalEle = m*n;
        int shift = k%totalEle;
        for (int i = 0; i < grid.size(); i++) {
            if (shift < n) {
                r = i;
                c = shift;
                break;
            }
            shift = shift - n;
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) { 
                matrix[r][c] = grid[i][j];
                c += 1;
                if (c >= n) {
                    c = 0; r += 1;
                    if (r >= m) r = 0;
                }
            } 
        }
        return matrix;
    }
};

int main() {
    Solution sol;
    int k = 5;
    vector<vector<int>>grid = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int>>ans =  sol.shiftGrid(grid, k);
    print_matrix(ans);
    return 0;
}