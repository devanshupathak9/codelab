class Soluton:
    def twoSum(self, nums, target):
        mapper = dict()
        for i in range(len(nums)):
            if mapper.get(target - nums[i]) != None:
                return [i, mapper.get(target - nums[i])]
            mapper[nums[i]] = i
        return []
    
def main():
    arr = [7, 2, 5, 11]
    target = 9
    sol = Soluton()
    res = sol.twoSum(arr, target)
    print(res)

if __name__ == "__main__":
    main()