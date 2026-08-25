class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        s = set(nums)
        i = 1
        while k * i in s:
            i += 1
        return k * i