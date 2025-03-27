class Solution(object):
    def lengthOfLIS(self, nums):
        temp = [1] * len(nums)
        max_element = 1
        
        for i in range(len(nums)):
            temp[i] = 1
            for j in range(i):
                if nums[j] < nums[i]:
                    temp[i] = max(temp[i],temp[j] + 1)
            max_element = max(temp[i],max_element)
        return max_element