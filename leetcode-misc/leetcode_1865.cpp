// 1865. Finding Pairs With a Certain Sum
// You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

// Add a positive integer to an element of a given index in the array nums2.
// Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
// Implement the FindSumPairs class:

// FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
// void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
// int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

template <typename T> 
void print(T value) { cout << value << "\n"; }

class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int>umap;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(auto it: this->nums2) this->umap[it]++;
    }
    void add(int index, int val) {
        this->umap[this->nums2[index]] -= 1;
        this->nums2[index] += val;
        this->umap[this->nums2[index]] += 1;
    }
    int count(int tot) {
        int count = 0;
        for(auto it: this->nums1) {
            if (this->umap.find(tot - it) != this->umap.end()) {
                count += this->umap[tot - it];
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums1 = {1, 1, 2, 2, 2, 3};
    vector<int> nums2 = {1, 4, 5, 2, 5, 4};
    FindSumPairs obj(nums1, nums2);
    obj.add(3, 2);
    print(obj.count(4));
    return 0;
}