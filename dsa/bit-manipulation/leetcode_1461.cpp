// 1461. Check If a String Contains All Binary Codes of Size K
// Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

// Example 1:
// Input: s = "00110110", k = 2
// Output: true
// Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.

// Example 2:
// Input: s = "0110", k = 1
// Output: true
// Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 

// Example 3:
// Input: s = "0110", k = 2
// Output: false
// Explanation: The binary code "00" is of length 2 and does not exist in the array.

#include <iostream> 
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

template <typename T>
void print(T value) { cout << value << "\n"; }

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int num = 0;
        int count = 0;
        if (k >= n) return false;
        unordered_set <int> st;
        int numOfValues = pow(2, k);
        int maxValue = pow(2, k) - 1;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (i < k-1) {
                num = num + pow(2, i)*(c - '0');
            }
            else if (i == k-1) {
                num = num + pow(2, i)*(c - '0');
                if (st.find(num) == st.end() && num <= maxValue) {
                    st.insert(num);
                    count ++;
                }
             }
            else {
                num = num/2;
                num = num + pow(2, k - 1)*(c - '0');
                if (st.find(num) == st.end() && num <= maxValue) {
                    st.insert(num);
                    count ++;
                }
            }
        }
        if (count == numOfValues) return true;
        return false;
    }
};

int main() {
    Solution Sol;
    string s = "00110110";
    int k = 2;
    print(Sol.hasAllCodes(s, k));
    return 0;
}