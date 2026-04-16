// 3713. Longest Balanced Substring I
// You are given a string s consisting of lowercase English letters.
// A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
// Return the length of the longest balanced substring of s.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void print(const T& value) {cout << value <<"\n";}

bool check(const vector<int> &umap, int start) {
    for(int i=0; i<26; i++){
        if (umap[i] != 0){
            if (umap[i] != umap[start]) return false;
        }
    }
    return true;
}

int solve(const string &word) {
    int maxSubstr = 0;
    int n = word.size();
    for(int i = 0; i < n; i++) {
        vector<int> umap(26, 0);
        for(int j = i; j < n; j++) 
        {
            umap[word[j] - 'a'] += 1;
            if(check(umap, word[i] - 'a')) {
                maxSubstr = max(maxSubstr, j - i + 1);
            }
        }
    }
    return maxSubstr;
}

int main() {
    string str = "ccabzzba";
    int res = solve(str);
    print(res);
    return 0;
}