class Solution:
  def splitArray(self, nums: list[int], k: int) -> int:
    def canSplit(target_max_sum: int) -> bool:
      subarrays = 1
      current_sum = 0
      for num in nums:
        if current_sum + num > target_max_sum:
          subarrays += 1
          current_sum = num
          if subarrays > k:
            return False
        else:
          current_sum += num
      return True

    low, high = max(nums), sum(nums)
    ans = high

    while low <= high:
      mid = (low + high) // 2
      if canSplit(mid):
        ans = mid
        high = mid - 1  # try for a smaller max sum
      else:
        low = mid + 1  # need a larger max sum

    return ans
