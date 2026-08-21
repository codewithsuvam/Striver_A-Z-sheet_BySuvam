from math import gcd
from itertools import combinations

class Solution:
    def findKthSmallest(self, coins: list[int], k: int) -> int:
        n = len(coins)

        def lcm(a: int, b: int) -> int:
            return a * b // gcd(a, b)

        def count(m: int) -> int:
            total = 0
            # iterate over all non-empty subsets using bitmask
            for mask in range(1, 1 << n):
                l = 1
                bits = 0
                overflow = False
                for i in range(n):
                    if mask & (1 << i):
                        bits += 1
                        l = lcm(l, coins[i])
                        if l > m:
                            overflow = True
                            break
                if overflow:
                    continue
                if bits % 2 == 1:
                    total += m // l
                else:
                    total -= m // l
            return total

        lo, hi = 1, k * min(coins)
        while lo < hi:
            mid = (lo + hi) // 2
            if count(mid) >= k:
                hi = mid
            else:
                lo = mid + 1

        return lo