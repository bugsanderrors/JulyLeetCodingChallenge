"""
    Ugly Number II

    Write a program to find the n-th ugly number.

    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

    Example:
    Input: n = 10
    Output: 12
    Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

    Note:  
        * 1 is typically treated as an ugly number.
        * n does not exceed 1690.
"""

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        
        if n==1 :
            return 1
        
        dp = [0]*n
        
        p2, p3, p5 = 0, 0, 0
        
        dp[0] = 1
        
        for i in range(1, n):
            dp[i] = min(dp[p2]*2, dp[p3]*3, dp[p5]*5)
            
            if(dp[i] == dp[p2]*2):
                p2 += 1
            if(dp[i] == dp[p3]*3):
                p3 += 1
            if(dp[i] == dp[p5]*5):
                p5 += 1
                
        return dp[n-1]