"""
    Hamming Distance

    The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

    Given two integers x and y, calculate the Hamming distance.

    Note:
    0 ≤ x, y < 231.

    Example:

    Input: x = 1, y = 4

    Output: 2

    Explanation:
    1   (0 0 0 1)
    4   (0 1 0 0)
           ↑   ↑

    The above arrows point to positions where the corresponding bits are different.

"""

class Solution:
    def hammingDistance(self, x: int, y: int) -> int:

        #The XOR of two gives the number of position where bits are different
        
        
        # 4 ->   1 0 0
        # 1 ->   0 0 1
        #       -------
        # XOR    1 0 1
        # count number of 1s.
        
        z = x ^ y
        
        
        # bin converts the integer to its binary form.
        
        return str(bin(z)[2:]).count('1')
