from typing import List

class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        n = len(nums)
        valid_split = left_sum = 0
        total_sum = sum(nums)
        for i in range(n - 1):
            left_sum += nums[i]
            valid_split = (valid_split + 1 if left_sum >= total_sum - left_sum else valid_split)
        return valid_split

if __name__ == "__main__":
    sol = Solution()
    print(sol.waysToSplitArray([10, 4, -8, 7]))
    print(sol.waysToSplitArray([2, 3, 1, 0]))
