// 3121. Count the Number of Special Characters II
// You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

// Return the number of special letters in word.

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T> &value) {
    for(auto it: value) cout << it << " ";
    print("");
}

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int c = 0;
        int n = word.size();
        vector<int>counter(26, 0);
        for (int i = 0; i < n; i++) {
            int key = (int)word[i];
            print(key);
            if (key <= 90) {
                if (counter[key - 65] == 0) counter[key - 65] = -1;
                else if (counter[key - 65] == 1) counter[key - 65] = 2;
            } else {
                if (counter[key - 97] == 0) counter[key - 97] = 1;
                else if (counter[key - 97] == 2) counter[key - 97] = -1;                
            }
        }   
        for (auto count: counter) {
            if (count == 2) c++;
        }
        print_vector(counter);
        return c;
    }
};

int main() {
    string word = "aaAbbBaccC";
    Solution sol;
    int answer = sol.numberOfSpecialChars(word);
    print(answer);
    return 0;
}