// 1344. Angle Between Hands of a Clock
// Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

// Answers within 10-5 of the actual value will be accepted as correct.

#include <iostream>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;
        double minutes_degree = minutes*6;
        double hour_degree = (hour*60+minutes)*0.5;
        double diff = abs(minutes_degree - hour_degree);
        return min(diff, 360-diff);
    }
}; 

int main() {
    int hour = 3;
    int minutes = 27;
    Solution sol;
    cout << sol.angleClock(hour, minutes) << "\n";
    return 0;
}