// 1404. Number of Steps to Reduce a Number in Binary Representation to One
// Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
// If the current number is even, you have to divide it by 2.
// If the current number is odd, you have to add 1 to it.
// It is guaranteed that you can always reach one for all test cases.

// Example 1:

// Input: s = "1101"
// Output: 6
// Explanation: "1101" corressponds to number 13 in their decimal representation.
// Step 1) 13 is odd, add 1 and obtain 14.
// Step 2) 14 is even, divide by 2 and obtain 7.
// Step 3) 7 is odd, add 1 and obtain 8.
// Step 4) 8 is even, divide by 2 and obtain 4.
// Step 5) 4 is even, divide by 2 and obtain 2.
// Step 6) 2 is even, divide by 2 and obtain 1.

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

template <typename T>
void print(T value) {
    cout << value << "\n";
}

class Solution {
public:
    int numSteps(string s) {
        int countOne = 0;
        int counter = 0;
        stack<char> stck;
        for (int i = 0; i < s.size(); i++)
            stck.push(s[i]);
        while (stck.size() > 1) {
            if (stck.top() == '0')
                stck.pop();
            else {
                countOne = 0;
                while (stck.size() && stck.top() == '1') {
                    stck.pop();
                    countOne++;
                }
                if (stck.size())
                    stck.pop();
                stck.push('1');
                while (countOne) {
                    stck.push('0');
                    countOne--;
                }
            }
            counter++;
        }
        return counter;
    }
};

int main() {
    Solution sol;
    vector<string> test_cases = {"1101", "110110111000101", "101101001111011011111111011"};
    for (auto s : test_cases)
    {
        print(sol.numSteps(s));
    }
    return 0;
}