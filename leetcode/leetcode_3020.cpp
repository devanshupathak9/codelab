// 3020. Find the Maximum Number of Elements in Subset

// You are given an array of positive integers nums.

// You need to select a subset of nums which satisfies the following condition:

// You can place the selected elements in a 0-indexed array such that it follows the pattern: [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2). For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
// Return the maximum number of elements in a subset that satisfies these conditions.

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T> 
void print(T &value) {
    cout << value << "\n";
}

class Solution {
private:
    unordered_map<int, int> counter;
    unordered_map<int, bool> visited;
public:
    int checkSquare(int num) {
        int count = 0;
        while (counter.find(num) != counter.end() && num != 1) {
            int freq = counter[num];
            if (freq >= 2) {
                count += 2;
                visited[num] = true;
            } else {
                count += 1;
                break;
            }
            num = num*num;
        }
        return count - 2;
    }
    int underRoot(int num) {
        int count = 0;
        int f = counter[num];

        if (f == 1) {
            count = 1;
            int root = sqrt(num);
            if (root*root != num) return 0;
            num = root;
        }
        print(num);
        print(count);
        while (counter.find(num) != counter.end() && num != 1) {
            int freq = counter[num];
            if (freq >= 2) {
                count += 2;
                visited[num] = true;
            } else {
                break;
            }
            int root = sqrt(num);
            if (root*root != num) break;
            num = root;
        }
        return count;
    }
    int maximumLength(vector<int>& nums) { 
        for (auto num: nums) {
            counter[num] += 1;
            visited[num] = false;
        }
        int maxLenght = 1, maxlen;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (visited[num] || num == 1) continue;
            int count = counter[num];
            if (count == 1) {
                maxlen = underRoot(num);
            } else {
                maxlen = checkSquare(num) + underRoot(num) -2;
            }
            maxLenght = max(maxLenght, maxlen);
        }
        return maxLenght;
    }
};

int main() {
    vector<int> nums  = {1,16,49,16,121};
    Solution sol;
    int res = sol.maximumLength(nums);
    print(res);
    return 0;
}