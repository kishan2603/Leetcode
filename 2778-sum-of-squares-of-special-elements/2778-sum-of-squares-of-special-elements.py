class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        i = 1
        for ele in nums:
            if (n%i==0):
                ans += ele**2
            i += 1
        
        return ans
        