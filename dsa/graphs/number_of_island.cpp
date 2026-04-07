// 200. Number of Islands
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
private:
    vector<vector<int>> visited;
public:
    void dfs(vector<vector<char>> &grid, int i, int j, int row, int col) 
    {
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = 1;
        int x, y;
        pair<int, int>move, p;
        while (q.size()) 
        {
            p = q.front(); q.pop();
            x = p.first; 
            y = p.second;
            for (auto move: moves) {
                if (x + move.first < row && x + move.first >=0 && y + move.second < col && y + move.second >=0 && visited[x + move.first][y + move.second] == 0 && grid[x + move.first][y + move.second] == '1') {
                    q.push(make_pair(x + move.first, y + move.second));
                    visited[x + move.first][y + move.second] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid) {
        int row = grid.size();
        int col = grid[0].size();
        visited.resize(row, vector<int>(col, 0));
        int ans = 0;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c]=='1' && visited[r][c] == 0) {
                    dfs(grid, r, c, row, col);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    int res = sol.numIslands(grid);
    cout << res << endl;
}