from typing import List

class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)

        # suffix[i] = total stones from i to n-1
        suffix = [0] * (n + 1)

        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] + piles[i]

        dp = {}

        def solve(i, M):
            # All piles are taken
            if i >= n:
                return 0

            # Can take all remaining piles
            if 2 * M >= n - i:
                return suffix[i]

            if (i, M) in dp:
                return dp[(i, M)]

            best = 0

            # Take x piles
            for x in range(1, 2 * M + 1):
                opponent = solve(i + x, max(M, x))

                # Current player gets all remaining stones
                # except what opponent can get
                current = suffix[i] - opponent

                best = max(best, current)

            dp[(i, M)] = best
            return best

        return solve(0, 1)