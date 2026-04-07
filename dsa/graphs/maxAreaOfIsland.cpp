// 695. Max Area of Island
// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
// The area of an island is the number of cells with a value 1 in the island.
// Return the maximum area of an island in grid. If there is no island, return 0.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> visited;
    vector<pair<int, int>> moves = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

public:
    int findArea(vector<vector<int>> &grid, int i, int j, int m, int n)
    {
        queue<pair<int, int>> q;
        pair<int, int> p;
        q.push({i, j});
        int r, c;
        int islandArea = 1;
        while (q.size()) {
            p = q.front();
            q.pop();
            for (auto it : moves) {
                r = p.first + it.first;
                c = p.second + it.second;
                if (r >= 0 && c >= 0 && r < m && c < n && grid[r][c] == 1 && visited[r][c] == 0) {
                    q.push({r, c});
                    visited[r][c] = 1;
                    islandArea += 1;
                }
            }
        }
        return islandArea;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0, area = 0;
        visited.resize(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    visited[i][j] = 1;
                    area = findArea(grid, i, j, m, n);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 0, 0, 0}};
    Solution sol;
    cout << sol.maxAreaOfIsland(grid) << endl;
}