// Valid Anagram
// Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>chr(26, 0);
        for (char ch: s) {
            chr[ch - 97] += 1;
        }
        for (char ch: t) {
            chr[ch - 97] -= 1;
        }
        for (auto it: chr) {
            if (it != 0) return false;
        }
        return true;
    }
};

int main() {
    string s = "racecar";
    string t = "carracet";
    Solution sol;
    bool answer = sol.isAnagram(s, t);
    print(answer);
    return 0;
}