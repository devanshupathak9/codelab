from typing import List
class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        count = 0
        vowel = ['a', 'e', 'i' , 'o', 'u']
        prefix = []
        for word in words:
            count = count + 1 if word[0] in vowel and word[-1] in vowel else count
            prefix.append(count)
        result = list()
        for l,r in queries:
            result.append(prefix[r]-prefix[l-1] if l>=1 else prefix[r])
        return result
if __name__=="__main__":
    sol = Solution()
    print(sol.vowelStrings(["aba","bcb","ece","aa","e"], [[0,2],[1,4],[1,1]]))
    print(sol.vowelStrings(["a","e","i"], [[0,2],[0,1],[2,2]]))
