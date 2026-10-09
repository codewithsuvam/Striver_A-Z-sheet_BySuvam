class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        left, right = 1, m * n
        
        def enough(x: int) -> bool:
            count = 0
            for i in range(1, m + 1):
                count += min(x // i, n)
            return count >= k
        
        while left < right:
            mid = (left + right) // 2
            if enough(mid):
                right = mid
            else:
                left = mid + 1
                
        return left
