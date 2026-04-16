// 2515. Shortest Distance to Target String in a Circular Array
// You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.

// Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.
// Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.

// Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T> 
void print(T value) {
    cout << value << "\n";
}

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        if (words.at(startIndex) == target) return 0;
        int dist = 1;
        while (true) {
            if (words.at((startIndex + dist)%n) == target || words.at((n + startIndex - dist)%n) == target) {
                return dist;
            }
            if (((startIndex + dist)%n) == ((n + startIndex - dist)%n)) break;
            dist += 1;
        }
        return -1;
    }
};

int main() {
    vector<string> words = {"hello","i","am","leetcode","hello"};
    int startIndex = 1;
    string target = "hello";

    Solution sol;
    int res = sol.closestTarget(words, target, startIndex);
    print(res);
    return 0;
}