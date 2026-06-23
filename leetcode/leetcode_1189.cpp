// 1189. Maximum Number of Balloons
// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T> &value) {
    for (auto val: value) {
        cout << val << " ";
    }
    print("");
}

class Solution {
    public:
        int maxNumberOfBalloons(string text) {
            vector<int> counter(26,0);
            for (auto ch: text) {
                counter[ch - 97]++;
            }
            int a = counter[0];
            int b = counter[1];
            int l = counter[11]/2;
            int o = counter[14]/2;
            int n = counter[13];
            if (!a || !b || !l || !o || !n) return 0;
            return min(min(min(min(a,b),l),n), o);
        }
};

int main() {
    string text = "loonbalxballpoon";
    Solution sol;
    int response = sol.maxNumberOfBalloons(text);
    print(response);
    return 0;
}