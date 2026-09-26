// 3876. Construct Uniform Parity Array II
// You are given an array nums1 of n distinct integers.

// You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.

// For each index i, you must choose exactly one of the following (in any order):

// nums2[i] = nums1[i]​​​​​​​
// nums2[i] = nums1[i] - nums1[j], for an index j != i, such that nums1[i] - nums1[j] >= 1
// Return true if it is possible to construct such an array, otherwise return false.

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
# define MYMIN(a, b) ((a < b)? (a):(b))

bool uniformArray(int* nums1, int nums1Size) {
    int even = 0, odd = 0;
    int oddMin = INT_MAX, evenMin = INT_MAX;
    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i]&1) {
            odd++; 
            oddMin = MYMIN(oddMin, nums1[i]);
        } else {
            even++; 
            evenMin = MYMIN(evenMin, nums1[i]);
        }
    }
    if (even == 0 || odd == 0) return true;
    if (evenMin > oddMin) return true;
    return false;
}

int main() {
    int nums1[] = {1, 4, 7};
    int nums1Size = sizeof(nums1)/sizeof(int);
    bool res = uniformArray(nums1, nums1Size);
    printf("%d\n", res); 
    return 0;
}