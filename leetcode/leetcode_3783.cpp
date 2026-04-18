// 3783. Mirror Distance of an Integer
// You are given an integer n.

// Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.=
// Return an integer denoting the mirror distance of n​​​​​​​.
// abs(x) denotes the absolute value of x.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void print(T value) {
    cout << value << "\n";
}

class Solution {
public:
    string difference(string num, string rev) {
        string a, b;
        // cout << num << " " << rev << "\n";
        if (num.size() > rev.size() || (num.size() == rev.size() && num >= rev)) {
            // cout << num.size() << " " << rev.size() << "\n";
            a = num;
            b = rev;
        } else if (rev > num) {
            a = rev;
            b = num;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res = "";
        int carry = 0;
        int ch1, ch2;
        for (int i = 0; i < a.size(); i++) {
            ch1 = a[i] - '0';
            if (i < b.size()) ch2 = b[i] - '0';
            else ch2 = 0;
            if (carry) ch1 = ch1 - carry;
            if (ch2 > ch1) {
                ch1 += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res += (ch1 - ch2) + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string reverseNum(int n) {
        int rem, flag = 1;
        string rev = "";
        while (n) {
            rem = n%10;
            n = n/10;
            if (rem == 0 && flag) continue;
            else {
                flag = 0;
                rev += rem + '0';
            }
        }
        print(rev);
        return rev;
    }
    
    int mirrorDistance(int n) {
        string num = to_string(n);
        string rev = reverseNum(n);
        string diff = difference(num, rev);
        return stoi(diff);
    }
};

int main() {
    int n = 203;
    Solution sol;
    print(sol.mirrorDistance(n));
    return 0;
}