// Climbing Stairs
// You are given an integer n representing the number of steps to reach the top of a staircase. You can climb with either 1 or 2 steps at a time.

// Return the number of distinct ways to climb to the top of the staircase.

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

class Solution {
public:
    int climbStairs(int n) {
        if ( n <= 2) return n;
        vector<int>stairs(n + 1, 0);
        stairs[0] = 0;
        stairs[1] = 1;
        stairs[2] = 2;
        for (int i = 3; i <= n; i++) {
            stairs[i] = stairs[i-1] + stairs[i-2];
        }
        return stairs[n];
    }
};

int main() {
    Solution sol;
    int answer = sol.climbStairs(5);
    print(answer);
    return 0;
}
