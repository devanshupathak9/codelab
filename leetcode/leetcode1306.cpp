// 1306. Jump Game III
// Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

// Notice that you can not jump outside of the array at any time
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
    for(auto it: value) cout << it << " ";
    print("");
}
class Solution
{
public:
    bool canReach(vector<int> &arr, int start) {
        int n = arr.size();

        vector<bool> visited(n, 0);
        visited[start] = true;
        print_vector(visited);

        queue<int> q;
        q.push(start);
    
        while (q.size())
        {
            int i = q.front();
            q.pop();
            int val = arr[i];
            if (val == 0) return true;
            if (i + arr[i] < n && !visited[i + arr[i]]) {
                visited[i + arr[i]] = true;
                q.push(i + arr[i]);
            }
            if (i - arr[i] >= 0 && !visited[i - arr[i]]) {
                visited[i - arr[i]] = true;
                q.push(i - arr[i]);
            }
        }
        return false;
    }
};

int main()
{
    vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
    int start = 5;
    Solution sol;
    bool answer = sol.canReach(arr, start);
    print(answer);
    return 0;
}