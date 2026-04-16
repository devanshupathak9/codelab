// 3333. Find the Original Typed String II
// Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
// You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.
// Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.
// Since the answer may be very large, return it modulo 109 + 7.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int possibleStringCount(string word, int k)
    {
        int n = word.size();
        int count = 0;
        vector<int> vec;
        for (int i = 0; i < n; i++){
            if (i == 0){
                count = 1; continue;
            }
            if (word[i] != word[i - 1]){
                vec.push_back(count); count = 1;
            }
            else count += 1;
        }
        if (count) vec.push_back(count);
        
        return -1;
    }
};
int main()
{
    Solution sol;
    string word = "aaaabbaaabfffnnrttthu";
    int k = 5;
    cout << sol.possibleStringCount(word, k);
}