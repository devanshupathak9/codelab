// 67. Add Binary
// Given two binary strings a and b, return their sum as a binary string.
// Example 1:
// Input: a = "1010", b = "1011"
// Output: "10101"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void print(T value) { cout << value << "\n"; }

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string res = "";
        char carry = '0';
        char c;
        while (i >= 0 || j >=0) {
            char ch1 = (i >=0)? a[i]: '0';
            char ch2 = (j >=0 )? b[j]: '0';
            if (ch1 == ch2 && ch1 == '0') {
                c = (carry == '1')? '1': '0';
                carry = '0';
            }
            else if (ch1 != ch2) {
                c = (carry == '1')? '0': '1';
            }
            else {
                c = (carry == '1')? '1': '0';
                carry = '1';
            }
            res += c;
            i--; j--;
        }

        if (carry == '1') res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    string a = "1010";
    string b = "1011";
    string res = sol.addBinary(a, b);
    print(res);
    return 0;
}