"""
    Arranging Coins

    You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

    Given n, find the total number of full staircase rows that can be formed.

    n is a non-negative integer and fits within the range of a 32-bit signed integer.

    Example 1:
    n = 5
    The coins can form the following rows:
    ¤
    ¤ ¤
    ¤ ¤
    Because the 3rd row is incomplete, we return 2.

    Example 2:
    n = 8
    The coins can form the following rows:
    ¤
    ¤ ¤
    ¤ ¤ ¤
    ¤ ¤
    Because the 4th row is incomplete, we return 3.
"""

class Solution:
    def arrangeCoins(self, n: int) -> int:
        
        #Approach 1 O(N)
        if n==1:
            return 1

        for i in range(1, n+1):
            x = i*(i+1)//2
            
            if x > n:
                return i-1
        
        return 0

        #Approach 2 O(log N)
        # return (int)((2 * n + 0.25)**0.5 - 0.5)