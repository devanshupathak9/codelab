# 3635. Earliest Finish Time for Land and Water Rides II
# You are given two categories of theme park attractions: land rides and water rides.

# Land rides
# landStartTime[i] – the earliest time the ith land ride can be boarded.
# landDuration[i] – how long the ith land ride lasts.
# Water rides
# waterStartTime[j] – the earliest time the jth water ride can be boarded.
# waterDuration[j] – how long the jth water ride lasts.
# A tourist must experience exactly one ride from each category, in either order.

# A ride may be started at its opening time or any later moment.
# If a ride is started at time t, it finishes at time t + duration.
# Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.
# Return the earliest possible time at which the tourist can finish both rides.


from typing import List
class Solution:
    def solve(self, fin1, dur1, fin2, dur2):
        finish1 = 10**9
        for i in range(len(fin1)):
            finish1 = min(finish1, fin1[i] + dur1[i])

        finish2 = 10**9
        for i in range(len(fin2)):
            finish2 = min(finish2, max(finish1, fin2[i]) + dur2[i])
        return finish2

    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        land2water = self.solve(landStartTime, landDuration, waterStartTime, waterDuration)
        water2land = self.solve(waterStartTime, waterDuration, landStartTime, landDuration)
        return min(land2water, water2land)
        
def main():
    landStartTime, landDuration = [5], [3]
    waterStartTime, waterDuration = [1], [10]
    sol = Solution()
    print(sol.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration))

main()