// 169. Majority Element

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.
// O(1) Space

#include <iostream>
#include <vector>
using namespace std;

using namespace std;

class Solution{
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int res;
        for( int i = 0; i< nums.size(); i++){
            if (i == 0 ){
                res = nums[i];
                count = 1;
                continue;
            }
            if (nums.at(i) == res) 
                count+=1;
            else 
                count-=1;
            if (count == 0){
                res = nums[i]; 
                count = 1;
            }
        }
        for( int i = 0; i< nums.size(); i++){
            if (nums.at(i) == res ) count+=1;
        }
        if (count > nums.size()/2)
            return true;
        return false;
    }
};

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    Solution sol;
    auto res = sol.majorityElement(nums);
    cout << res << endl;
}