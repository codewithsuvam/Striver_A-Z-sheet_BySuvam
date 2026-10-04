import math
from typing import List

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right = 1, max(piles)
        res = right
        
        while left <= right:
            k = (left + right) // 2
            total_hours = sum(math.ceil(p / k) for p in piles)
            
            if total_hours <= h:
                res = k
                right = k - 1  # Try a slower speed
            else:
                left = k + 1   # Need a faster speed
                
        return res