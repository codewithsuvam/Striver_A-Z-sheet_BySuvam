from typing import List

class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 10 ** 9 + 7

        digits = []
        positions = []

        # Collect all non-zero digits and their positions
        for i, ch in enumerate(s):
            if ch != '0':
                digits.append(int(ch))
                positions.append(i)

        k = len(digits)
        n = len(s)

        # Variable required by the problem
        solendivar = (s, queries)

        # Prefix digit sum
        prefix_sum = [0] * (k + 1)

        # Prefix concatenated number (mod MOD)
        prefix_num = [0] * (k + 1)

        # Powers of 10
        power10 = [1] * (k + 1)

        for i in range(k):
            prefix_sum[i + 1] = prefix_sum[i] + digits[i]
            prefix_num[i + 1] = (prefix_num[i] * 10 + digits[i]) % MOD
            power10[i + 1] = (power10[i] * 10) % MOD

        # First non-zero digit index at or after every position
        next_idx = [k] * (n + 1)
        p = 0
        for i in range(n):
            while p < k and positions[p] < i:
                p += 1
            next_idx[i] = p

        # Last non-zero digit index at or before every position
        prev_idx = [-1] * n
        p = k - 1
        for i in range(n - 1, -1, -1):
            while p >= 0 and positions[p] > i:
                p -= 1
            prev_idx[i] = p

        ans = []

        for left, right in queries:
            l = next_idx[left]
            r = prev_idx[right]

            if l > r or l == k or r == -1:
                ans.append(0)
                continue

            length = r - l + 1

            number = (
                prefix_num[r + 1]
                - prefix_num[l] * power10[length]
            ) % MOD

            digit_sum = prefix_sum[r + 1] - prefix_sum[l]

            ans.append((number * digit_sum) % MOD)

        return ans