class Solution:
    def removeDuplicates(self, nums):
        k=0 
        for i in nums:
            if nums.count(i)>1:
                nums.pop(nums.index(i))
                k+=1
        return k        
num = [1,1,2]

s = Solution()
print(s.removeDuplicates(num))
print(num)
# nums = [2,7,11,15]
# target = 9  
# print(s.twoSum(nums,target))

# nums = [3,2,4]
# target = 6
# print(s.twoSum(nums,target))

# nums = [3,3]
# target = 6
 
# print(s.twoSum(nums,target))