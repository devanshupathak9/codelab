// 695. Max Area of Island
// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
// The area of an island is the number of cells with a value 1 in the island.
// Return the maximum area of an island in grid. If there is no island, return 0.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
private:
    vector<vector<int>> visited;
public:
    int dfs(vector<vector<int>>& grid, int r, int c, int row, int col) {
        int i, j, f, s, count = 1;
        stack<pair<int, int>> stk;
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        stk.push({r, c});
        visited[r][c] = 1;
        while (stk.size()) {
            pair<int, int>p = stk.top(); 
            stk.pop();
            i = p.first; 
            j = p.second;
            for(auto move: moves) {
                f = i + move.first; s = j + move.second;
                if (f >= 0 && s >=0 && f < row && s < col && grid[f][s] == 1 && visited[f][s]==0){
                    stk.push(make_pair(f, s)); 
                    visited[f][s] = 1;
                    count +=1;
                }
            }
        }
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int row = grid.size();
        int col = grid[0].size();
        visited.resize(row, vector<int>(col, 0));
        for (int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                if (grid[r][c] == 1 && visited[r][c] == 0) {
                    area = max(area, dfs(grid, r, c, row, col));
                }
            }
        }
        return area;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 0, 0, 0}
    };
    int ans = sol.maxAreaOfIsland(grid);
    cout << ans << endl;
}