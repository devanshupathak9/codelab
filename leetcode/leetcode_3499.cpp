// 3499. Maximize Active Section with Trade I
// You are given a binary string s of length n, where:

// '1' represents an active section.
// '0' represents an inactive section.
// You can perform at most one trade to maximize the number of active sections in s. In a trade, you:

// Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
// Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
// Return the maximum number of active sections in s after making the optimal trade.

// Note: Treat s as if it is augmented with a '1' at both ends, forming t = '1' + s + '1'. The augmented '1's do not contribute to the final count.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        char prevValue = '2';
        int countZero = 0;
        int maxSession = 0;
        int current, prev = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                countZero += 1;
            } else {
                ones += 1;
                if (prevValue == '2') {
                    prevValue = s[i];
                    continue;
                } 
                if (prevValue == '0') {
                    current = countZero;
                    if (prev!=-1) {
                        maxSession = max(maxSession, current + prev);
                    }
                    prev = current;
                    countZero = 0;
                }
            }
            prevValue = s[i];
        }
        if (countZero > 0 && prev != -1) {
            maxSession = max(maxSession, countZero + prev);
        }
        return maxSession + ones;
    }
};

int main() {
    string s = "001000100111101110110110000000111100000";
    Solution Sol;
    int ans = Sol.maxActiveSectionsAfterTrade(s);
    cout << ans << "\n";
    return 0;
}