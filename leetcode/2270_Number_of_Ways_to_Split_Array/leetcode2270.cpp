#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution{
    public:
    int waysToSplitArray(vector<int>&nums){
        int n = nums.size();
        int split_count = 0;
        long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long left_sum = 0;
        for (int i = 0; i<n-1; i++){
            left_sum += nums.at(i);
            if (left_sum >= total_sum-left_sum) split_count += 1;
        }
        return split_count;
    }
};
int main(){
    Solution Sol;
    vector<int>vec={10,4,-8,7};
    cout<<Sol.waysToSplitArray(vec)<<endl;
}