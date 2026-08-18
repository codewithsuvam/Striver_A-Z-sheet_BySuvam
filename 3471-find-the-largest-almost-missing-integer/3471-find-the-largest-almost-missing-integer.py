class Solution:
    def largestInteger(self, nums, k):
        n = len(nums)

        count = {}

        # Count how many windows of size k contain each number
        for i in range(n - k + 1):
            seen = set(nums[i:i + k])

            for x in seen:
                count[x] = count.get(x, 0) + 1

        # Find the largest number appearing in exactly one window
        ans = -1

        for x in count:
            if count[x] == 1:
                ans = max(ans, x)

        return ans