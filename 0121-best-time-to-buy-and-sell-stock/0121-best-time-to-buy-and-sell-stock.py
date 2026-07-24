class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        curr = prices[0]
        maxi = 0
        for i in range(len(prices)-1):
            if curr<prices[i+1]:
                maxi = max(maxi,prices[i+1]-curr)
            else:
                curr = prices[i+1]
        return maxi