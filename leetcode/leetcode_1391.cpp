// 1391. Check if There is a Valid Path in a Grid
// You are given an m x n grid. Each cell of grid represents a street. The street of grid{i}{j} can be:

// 1 which means a street connecting the left cell and the right cell.
// 2 which means a street connecting the upper cell and the lower cell.
// 3 which means a street connecting the left cell and the lower cell.
// 4 which means a street connecting the right cell and the lower cell.
// 5 which means a street connecting the left cell and the upper cell.
// 6 which means a street connecting the right cell and the upper cell.

// You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

// Notice that you are not allowed to change any street.

// Return true if there is a valid path in the grid or false otherwise.

#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int,int>;

const pii UP = {-1, 0};
const pii DOWN = {1, 0};
const pii LEFT = {0, -1};
const pii RIGHT = {0, 1};

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T> &value) {
    for(auto it: value) cout << it << " ";
    print(" ");
}


class Solution {
private:
    int m, n;
    vector<vector<int>> grid;
    vector<pair<int, int>>actions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool>> visited;
    unordered_map<int, vector<pii>> moves = {
        {1, {LEFT, RIGHT}},
        {2, {UP, DOWN}},
        {3, {LEFT, DOWN}},
        {4, {RIGHT, DOWN}},
        {5, {LEFT, UP}},
        {6, {RIGHT, UP}}
    };

    bool isValid(int x, int y) {
        if (x >=0 && y>=0 && x<m && y<n) return true;
        return false;
    }

    bool checkNextState(int i, int j, int x, int y) {
        int curr = grid[i][j];
        int next = grid[x][y];

        int dx = x - i;
        int dy = y - j;

        // moving RIGHT
        if (dx == 0 && dy == 1) {
            if (curr == 1 || curr == 4 || curr == 6) {
                return (next == 1 || next == 3 || next == 5);
            }
        }
        if (dx == 0 && dy == -1) {
            if (curr == 1 || curr == 3 || curr == 5) {
                return (next == 1 || next == 4 || next == 6);
            }
        }
        if (dx == 1 && dy == 0) {
            if (curr == 2 || curr == 3 || curr == 4) {
                return (next == 2 || next == 5 || next == 6);
            }
        }
        if (dx == -1 && dy == 0) {
            if (curr == 2 || curr == 5 || curr == 6) {
                return (next == 2 || next == 3 || next == 4);
            }
        }

        return false;
    }

public:
    bool dfs(int i, int j) {
        cout << i << " " << j << "\n";
        if (i == m-1 && j == n - 1) return true;
        visited[i][j] = true;
        int street = grid[i][j];
        vector<pii> action = moves[street];

        for (auto it: action) {
            int x = i + it.first;
            int y = j + it.second;
            if (isValid(x, y) && checkNextState(i, j, x, y) && !visited[x][y]) {
                if (dfs(x, y)) return true;
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& g) {
        grid = g;
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));
        bool res = dfs(0, 0);
        return res;
    }
};

int main() {
    vector<vector<int>> grid1 = {{2,4,3},{6,5,2}};
    vector<vector<int>> grid2 = {{1,2,1},{1,2,1}};
    vector<vector<int>> grid3 = {{4, 1},{6, 1}};
    Solution sol;
    bool answer = sol.hasValidPath(grid3);
    print(answer);
    return 0;
}