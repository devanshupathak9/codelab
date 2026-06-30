// 1358. Number of Substrings Containing All Three Characters
// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
// Example 3:

// Input: s = "abc"
// Output: 1
 

// Constraints:

// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters.


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> counter = vector<int>(3, 0);
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;
        int i = 0, j = 0;
        int a = 0, b = 0, c = 0;
        while (i <= n - 3 && j < n) {
            char ch = s[j];
            this->counter[ch - 'a'] += 1;
            while (this->counter[0] && this->counter[1] && this->counter[2]) {
                count += n - j;
                char ch2 = s[i];
                this->counter[ch2 - 'a'] -= 1;
                i += 1;
            }
            j += 1;
        }
        return count;
    }
};

int main() { 
    string s = "abcabc";
    Solution sol;
    cout << sol.numberOfSubstrings(s) << "\n";
    return 0;
}