// 3160. Find the Number of Distinct Colors Among the Balls
// You are given an integer limit and a 2D array queries of size n x 2.
// There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of colors among the balls.
// Return an array result of length n, where result[i] denotes the number of colors after ith query.
// Note that when answering a query, lack of a color will not be considered as a color.


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballMap;
        unordered_map<int, int> colorMap;
        vector<int> result;
        int colorCount = 0;
        for (auto& it: queries){
            int x = it[0]; 
            int y = it[1];
            if (colorMap.find(y) == colorMap.end() || colorMap[y] == 0) {
                colorCount ++;
                int prevcolor = ballMap[x];
                if (prevcolor != 0) {
                    colorMap[prevcolor] -=1;
                    if (colorMap[prevcolor] == 0){
                        colorCount--;
                    }
                }
                colorMap[y] += 1;
                ballMap[x] = y;
            }
            else {
                int prevcolor = ballMap[x];
                if (prevcolor != 0){
                    colorMap[prevcolor] -= 1;
                    if (colorMap[prevcolor] == 0) {
                        colorCount--;
                    }
                }
                if (colorMap[y] == 0) {
                    colorCount++;
                }
                ballMap[x] = y;
                colorMap[y] += 1;
            }
            result.push_back(colorCount);
        }
        return result;
    }
};

int main() {
    Solution sol;
    int limit = 1;
    vector<vector<int>> queries = {{0,1},{0,4},{0,4},{0,1},{1,2}};
    auto res = sol.queryResults(limit, queries);
    for (int count : res) {
        cout << count << " ";       
    }
    cout << endl;
}