#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool checkVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> result;
        vector<int> prefix = {0};
        int count = 0;

        for (const auto& word : words) {
            if (checkVowel(word.front()) && checkVowel(word.back())) {
                count++;
            }
            prefix.push_back(count);
        }
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int ans = prefix[r + 1] - prefix[l];
            result.push_back(ans);
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
    vector<int> res = sol.vowelStrings(words, queries);
    for (int val : res) {
        cout << val << " ";
    }
}
