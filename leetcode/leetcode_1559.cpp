// 1559. Detect Cycles in 2D Grid
// Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.
// A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.
// Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.
// Return true if any cycle of the same value exists in grid, otherwise, return false.

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T> &value) {
    for(auto it: value) cout << it << " ";
    print("");
}


class Solution {
private:
    int m, n;
    vector<vector<char>> grid;
    vector<vector<bool>>visited;

    vector<pair<int, int>>actions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool isValid(int x, int y) {
        if (x >=0 && y>=0 && x<m && y<n) return true;
        return false;
    }

    bool checkParent(int i, int j, pair<int, int>parent) {
        if (i == parent.first && j == parent.second) return false;
        return true;
    }
public:
    bool dfs(int i, int j, pair<int, int>parent) {
        int x, y;
        visited[i][j] = true;
        
        for(auto it: actions) {
            int x = i + it.first;
            int y = j + it.second;
            if (isValid(x, y) && grid[x][y] == grid[i][j]) {
                if (!visited[x][y]) {
                    if (dfs(x, y, {i, j})) return true;
                }
                else if (checkParent(x, y, parent)) return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& g) {
        grid = g;
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for (int j =0; j <n; j++) {
                if (visited[i][j] == false) {
                    if (dfs(i, j, {-1,-1})) return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>>grid = {{'c','c','c','a'},{'c','d','c','c'},{'c','c','e','c'},{'f','c','c','c'}};
    Solution sol;
    bool ans = sol.containsCycle(grid);
    print(ans);
    return 0;
}