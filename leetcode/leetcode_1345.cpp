// 1345. Jump Game IV
// Given an array of integers arr, you are initially positioned at the first index of the array.

// In one step you can jump from index i to index:

// i + 1 where: i + 1 < arr.length.
// i - 1 where: i - 1 >= 0.
// j where: arr[i] == arr[j] and i != j.
// Return the minimum number of steps to reach the last index of the array.

// Notice that you can not jump outside of the array at any time.

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(set<T> &value) {
    for(auto it: value) cout << it << " ";
    print("");
}

class Solution {
public:
    bool is_valid(int i, int n) {
        if (i >=0 && i <n) return true;
        return false;
    }
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>>umap;
        unordered_map<int, set<int>>grid;
        for (int i = 0; i < arr.size(); i++) {
            umap[arr[i]].push_back(i);
        }
        queue<pair<int, int>>q;
        vector<bool>visited (n, 0);
        q.push({0, 0});
        visited[0] = true;
        int dist, min_jumps = INT32_MAX;
        while (q.size()) {
            pair<int, int>p = q.front(); 
            q.pop();
            int pos = p.first;
            int dist = p.second;
            if (pos == n-1) return dist;
            if (is_valid(pos + 1, n) && !visited[pos + 1]) {
                visited[pos + 1] = true;
                q.push({pos + 1, dist + 1});
            }
            if (is_valid(pos - 1, n) && !visited[pos - 1]) {
                visited[pos - 1] = true;
                q.push({pos - 1, dist + 1});
            }
            for (auto it: umap[arr[pos]]) {
                if (it != pos && !visited[it]) {
                    visited[it] = true;
                    q.push({it, dist + 1});
                }
            }
            umap.erase(arr[pos]);
        }
        return min_jumps;
    }
};

int main() {
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    Solution  sol;
    int answer = sol.minJumps(arr);
    print(answer);
    return 0;
}