"""
1007. Minimum Domino Rotations For Equal Row
In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino.
(A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
If it cannot be done, return -1.
"""

from typing import List, Dict
from collections import Counter


class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        def checkswaps(arr1, arr2):
            count = 0
            for i in range(len(arr1)):
                if arr2[i] == val and arr1[i] != val:
                    count += 1
                if arr2[i] != val and arr1[i] != val:
                    return -1
            return count

        n = len(tops)
        counter = Counter(tops + bottoms)
        val, count = counter.most_common(1)[0]
        if count < n:
            return -1
        res = (
            checkswaps(tops, bottoms)
            if (tops.count(val) > bottoms.count(val))
            else checkswaps(bottoms, tops)
        )
        return res
    
if __name__ == "__main__":
    sol = Solution()
    tops: List[int] = [1,2,1,1,1,2,2,2]
    bottoms: List[int] = [2,1,2,2,2,9,2,2]
    print(sol.minDominoRotations(tops, bottoms))

