// 1513. Number of Substrings With Only 1s
// Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.

#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007

class Solution {
public:
    int numSub(string s) {
        long int total_substrings = 0;
        long int counter = 0;
        for (int i =0; i<s.size(); i++) {
            if (s[i] == '1') counter++;
            else {
                total_substrings += counter + (counter*(counter-1))/2;
                counter = 0;
            }
        }
        if (counter) total_substrings += counter + (counter*(counter-1))/2;
        return total_substrings%mod;
    }
};

int main() {
    string s = "110010011110111111000011";
    Solution sol;
    cout <<sol.numSub(s)<<"\n";
}