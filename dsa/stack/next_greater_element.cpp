#include <iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextLargerElement(vector<int> &arr){
        int n = arr.size();
        vector<int>res;
        stack<int> stck;
        for(int i = n-1; i >= 0; i--) {
            int curr = arr[i];
            while (stck.size() && curr > stck.top()) {
                stck.pop();
            }
            if (stck.size()) res.push_back(stck.top());
            else res.push_back(-1);
            stck.push(curr);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    vector<int> arr = {13, 7, 6, 12, 10, 16, 5, 18, 3, 2, 25, 1};
    Solution sol;
    vector<int> result = sol.nextLargerElement(arr);
    for (auto it: result) { cout << it << " "; }
    cout << "\n";
    return 0;
}