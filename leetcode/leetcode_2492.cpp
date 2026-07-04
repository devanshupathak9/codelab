// 2492. Minimum Score of a Path Between Two Cities
// You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.
// The score of a path between two cities is defined as the minimum distance of a road in this path.
// Return the minimum possible score of a path between cities 1 and n.
// Note:
// A path is a sequence of roads between two cities.
// It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
// The test cases are generated such that there is at least one path between 1 and n.

// Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
// Output: 5
// Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
// It can be shown that no other path has less score.

// Example 2:
// Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
// Output: 2
// Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.
 
// Constraints:
// 2 <= n <= 105
// 1 <= roads.length <= 105
// roads[i].length == 3
// 1 <= ai, bi <= n
// ai != bi
// 1 <= distancei <= 104
// There are no repeated edges.
// There is at least one path between 1 and n.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T> &value) {
    for (auto it: value)
        cout << it << " ";
    print("");
}


class Solution{
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
        for (int i = 0; i < roads.size(); i++) {
            vector<int> path = roads[i];
            graph[path[0]].push_back({path[1], path[2]});
            graph[path[1]].push_back({path[0], path[2]});
        }
        queue<int> q;
        vector<bool> visited (n+1, false);
        q.push(1); visited[1] = true;
        while (q.size()) {
            int node = q.front(); q.pop();
            for (auto next: graph[node]) {
                int nb = next.first;
                if (visited[nb] == false) {
                    q.push(nb);
                    visited[nb] = true;
                }
            }
        }
        print_vector(visited);
        int minDist = 1000000;
        for (int i = 0; i < graph.size(); i++) {
            if (visited[i]) {
                for (auto it: graph[i]) {
                    minDist = min(minDist, it.second);
                }
            }
        }
        return minDist;
    }
};

int main() {
    int n = 14;
    vector<vector<int>> roads = {
        {2, 9, 2308},
        {2, 5, 2150},
        {12, 3, 4944},
        {13, 5, 5462},
        {2, 10, 2187},
        {2, 12, 8132},
        {2, 13, 3666},
        {4, 14, 3019},
        {2, 4, 6759},
        {2, 14, 9869},
        {1, 10, 8147},
        {3, 4, 7971},
        {9, 13, 8026},
        {5, 12, 9982},
        {10, 9, 6459}
    };
    Solution sol;
    int ans = sol.minScore(n, roads);
    print(ans);
    return 0;
}

