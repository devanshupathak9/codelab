// 401. Binary Watch
// A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.
// For example, the below binary watch reads "4:51".
// Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.
// The hour must not contain a leading zero.

// For example, "01:00" is not valid. It should be "1:00".
// The minute must consist of two digits and may contain a leading zero.
// For example, "10:2" is not valid. It should be "10:02"

#include <iostream>
#include <vector>
using namespace  std;

template <typename T>
void print(T value) { cout << value << "\n"; }

class Solution {
public: 
    vector<int> subset(int maxbit, int maxValue) {
        int counter = 0;
        vector<int>vect;
        for (int i = 0; i <= maxValue; i++) {
            counter = 0;
            for(int j = 0; j <6; j++) {
                if (i&(1<<j)) {
                    counter ++;
                }
            }
            if (counter == maxbit) vect.push_back(i);
        }
        return vect;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        if (turnedOn >=9)  return {};
        if (turnedOn == 0) return {"0:00"};
        int hourbit, minbit;
        vector<string> res = {};
        vector<pair<int, int>> time;
        for(int i = 0; i <= min(3, turnedOn); i++) {
            hourbit = i;
            minbit = turnedOn - i;
            vector<int> hourValue = subset(hourbit, 11);
            vector<int> minValue = subset(minbit, 59);
            for(auto h: hourValue) {
            for (auto m: minValue) {
                time.push_back({h, m});
            }
            }
        }
        sort(time.begin(), time.end());
        for (auto& t : time) {
            string s = to_string(t.first) + ":";
            if (t.second < 10) s += "0";
            s += to_string(t.second);
            res.push_back(s);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> testCases = { 0, 9, 3, 7 , 5};
    for (auto it: testCases) {
        print(it);
        vector<string> res = sol.readBinaryWatch(it);
        for (auto time: res) {
            cout << time << ", ";
        }
        print("\n------------------");
    }
    return 0;
}