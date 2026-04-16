"""
2918. Minimum Equal Sum of Two Arrays After Replacing Zeros

You are given two arrays nums1 and nums2 consisting of positive integers.
You have to replace all the 0's in both arrays with strictly positive integers;
such that the sum of elements of both arrays becomes equal.
Return the minimum equal sum you can obtain, or -1 if it is impossible.
"""

from typing import List, Dict


class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        sum1, sum2 = sum(nums1), sum(nums2)
        count1 = nums1.count(0)
        count2 = nums2.count(0)
        if count1 == 0 and count2 == 0:
            return sum1 if sum1 == sum2 else -1
        if count1 == 0 or count2 == 0:
            szero, czero, snonzero, cnonzero = (
                (sum1, count1 , sum2, count2) if count1 ==0 else (sum2, count2 , sum1, count1)
            )
            if snonzero >= szero:
                return -1
            else:
                return szero if snonzero + cnonzero<=szero else -1
        return max(sum1 + count1, sum2 + count2)


if __name__ == "__main__":
    sol = Solution()
    test_cases = [([3, 2, 0, 1, 0], [6, 5, 0]), ([2, 0, 2, 0], [1, 4])]
    for nums1, nums2 in test_cases:
        print(nums1, nums2)
        print(sol.minSum(nums1, nums2))
