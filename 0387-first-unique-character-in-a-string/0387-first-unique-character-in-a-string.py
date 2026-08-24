class Solution:
    def firstUniqChar(self, s: str) -> int:
        counts: dict[str, int] = {}

        for ch in s:
            counts[ch] = counts.get(ch, 0) + 1

        for i, ch in enumerate(s):
            if counts[ch] == 1:
                return i

        return -1