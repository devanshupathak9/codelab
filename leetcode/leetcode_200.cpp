// // 200. Number of Islands
// // Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// // An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    int n, m;
    vector<pair<int, int>> actions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    bool check(int i, int j) {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;
        return false;
    }
    void dfs(vector<vector<char>> &grid, int i, int j) {
        int x, y;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (q.size()) {
            pair<int, int> p = q.front();
            q.pop();
            for (auto it : actions) {
                x = p.first + it.first;
                y = p.second + it.second;
                if (check(x, y) && grid[x][y] == '1') {
                    q.push({x, y});
                    grid[x][y] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid) {
        int islandCounter = 0;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    islandCounter += 1;
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                }
            }
        }
        return islandCounter;
    }
};

template <typename T>
void print(T value)
{
    cout << value << "\n";
}

int main()
{
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '1'}};
    int result = sol.numIslands(grid);
    print(result);
    return 0;
}