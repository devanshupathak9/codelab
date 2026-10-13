// Number of Islands
// Given a 2D grid grid where '1' represents land and '0' represents water, count and return the number of islands.
// An island is formed by connecting adjacent lands horizontally or vertically and is surrounded by water. You may assume water is surrounding the grid (i.e., all the edges are water).

// Example 1:
// Input: grid = [
//     ["0","1","1","1","0"],
//     ["0","1","0","1","0"],
//     ["1","1","0","0","0"],
//     ["0","0","0","0","0"]
//   ]
// Output: 1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    bool isValid(int x, int y, int n, int m) {
        if (x >= 0 && y >=0 && x < n && y < m) return true;
        return false;
    }
    void bfs(vector<vector<char>>& grid, int n, int m, int x, int y) {
        queue<pair<int, int>>q;
        q.push({x, y});
        while (!q.empty()) 
        {
            pair<int, int> p = q.front(); q.pop();
            for (int k = 0; k < 4; k++) 
            {
                int i = p.first + dx[k];
                int j = p.second + dy[k];
                if (isValid(i, j, n, m) && grid[i][j] == '1') {
                    q.push({i, j});
                    grid[i][j] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    bfs(grid, n, m, i, j);
                    counter++;
                }
            }
        }
        return counter;
    }
};


int main() {
    Solution sol;

    vector<vector<char>> grid1 = {
        {'0', '1', '1', '1', '0'},
        {'0', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    cout << "Example 1 Output: "
         << sol.numIslands(grid1) << endl;

    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '1'},
        {'1', '1', '0', '0', '1'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "Example 2 Output: "
         << sol.numIslands(grid2) << endl;

    return 0;
}