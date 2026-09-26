#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template<typename T>
void printVector(vector<T>&value) {
    for(auto val: value) cout << val << " ";
    cout << "\n";
}

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums) {
        int n = nums.size();

        vector<int> res;
        stack<int> stck;
        for (int i = n-1; i >= 0; i--) {
            int num = nums[i];
            while (stck.size() && stck.top() < num) {
                stck.pop();
            }
            if (!stck.size()) res.push_back(-1);
            else res.push_back(stck.top());
            stck.push(num);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    vector<int> nums = {4, 1, 2, 5, 3, 6};
    Solution sol;
    vector<int> ans = sol.nextGreaterElement(nums);
    printVector(ans);
    return 0;
}



































// #include <iostream>
// #include <vector>
// using namespace std;

// template <typename T>
// void print_vector(vector<T>& value) {
//     for (auto val: value) cout << val << " ";
//     cout << "\n";
// }

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& arr) {
//         int n = arr.size();

//         vector<int> res;
//         stack<int> stck;

//         for (int i = n - 1; i >= 0; i--) {
//             int val = arr.at(i);
//             while (stck.size() && val > stck.top()) stck.pop();
//             if (stck.size()) res.push_back(stck.top());
//             else res.push_back(-1);
//             stck.push(val);
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };

// int main() {
//     vector<int> arr = {2, 1, 3, 4};
//     Solution sol;
//     vector<int> res = sol.nextGreaterElement(arr);
//     print_vector(res);
//     return 0;
// }