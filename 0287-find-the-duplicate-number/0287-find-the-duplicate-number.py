class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        # Phase 1: Cycle detect karo (Floyd's Tortoise and Hare)
        # nums[i] ko "next pointer" ki tarah treat karo
        slow = nums[0]
        fast = nums[0]

        # Pehle dono ko ek baar move kar do taaki loop me match check ho sake
        while True:
            slow = nums[slow]          # 1 step aage
            fast = nums[nums[fast]]    # 2 steps aage
            if slow == fast:           # cycle ke andar mil gaye
                break

        # Phase 2: Cycle ka entry point dhundo (yahi duplicate number hai)
        slow2 = nums[0]                # ek pointer wapas shuru se
        while slow != slow2:
            slow = nums[slow]          # ab dono 1-1 step chalenge
            slow2 = nums[slow2]

        # Jaha mile, wahi duplicate number hai
        return slow  