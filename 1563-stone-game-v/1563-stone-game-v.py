class Solution:
    def stoneGameV(self, stoneValue):
        n = len(stoneValue)

        # dp[i][j] = maximum score for subarray i...j
        dp = [[0] * n for _ in range(n)]

        # mx[i][j] stores:
        # max(dp[i][k] + sum(i...k)) for k <= j
        mx = [[0] * n for _ in range(n)]

        for i in range(n):
            mx[i][i] = stoneValue[i]

        for j in range(1, n):

            mid = j
            right = 0
            total = stoneValue[j]

            for i in range(j - 1, -1, -1):

                total += stoneValue[i]

                # Find the point where left sum >= right sum
                while mid > i and (right + stoneValue[mid]) * 2 <= total:
                    right += stoneValue[mid]
                    mid -= 1

                # Equal sums
                if right * 2 == total:
                    dp[i][j] = mx[i][mid]

                # Left side is smaller
                if mid != i:
                    dp[i][j] = max(
                        dp[i][j],
                        mx[i][mid - 1]
                    )

                # Right side is smaller
                if mid != j:
                    dp[i][j] = max(
                        dp[i][j],
                        mx[j][mid + 1]
                    )

                # Update prefix maximum
                mx[i][j] = max(
                    mx[i][j - 1],
                    dp[i][j] + total
                )

                # Update suffix maximum
                mx[j][i] = max(
                    mx[j][i + 1],
                    dp[i][j] + total
                )

        return dp[0][n - 1]