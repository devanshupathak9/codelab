// 74. Search a 2D Matrix
// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size(), column = matrix[0].size();
        int i = row - 1, j = 0, value;
        while (j < column && i >= 0)
        {
            value = matrix[i][j];
            if (value == target)
                return true;
            if (value < target)
                j += 1;
            else
                i -= 1;
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 73;
    Solution sol;
    cout << sol.searchMatrix(matrix, target) << endl;
}