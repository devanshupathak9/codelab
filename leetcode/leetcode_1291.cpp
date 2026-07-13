
// 1291. Sequential Digits
// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

// Example 1:

// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print_vector(vector<T> &value) {
    for(auto it: value) {
        cout << it << " ";
    }
    cout << "\n";
}

class Solution {
public:
    int size(int n) {
        int count = 0;
        while (n) {
            count += 1;
            n = n/10;
        }
        return count - 1;
    }
    vector<int> sequentialDigits(int low, int high) {
        int number;
        vector<int> numbers;
        bool flag = false;
        int lowSize = size(low);
        int highSize = size(high);
        for (int i = lowSize; i <= highSize; i++) 
        {
            for (int j = 1; j < 10; j++) 
            {
                number = 0;
                int current = j, power = i;
                while (current < 10 && power >= 0) {
                    number = number + current*pow(10, power);
                    power -= 1; current += 1;
                }
                if (power >= 0) break;
                else if (number >= low && number <= high) {
                    numbers.push_back(number);
                } else if (number > high){
                    flag = true; break;
                }
            }
            if (flag) break;
        }
        return numbers;  
    }
};

int main() {
    int low = 46, high = 4254;
    Solution sol;
    vector<int> res = sol.sequentialDigits(low, high);
    print_vector(res);
    return 0;
}