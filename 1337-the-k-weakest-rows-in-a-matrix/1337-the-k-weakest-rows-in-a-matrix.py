from typing import List

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        rows = []

        for i, row in enumerate(mat):
            left, right = 0, len(row)

            while left < right:
                mid = (left + right) // 2

                if row[mid] == 1:
                    left = mid + 1
                else:
                    right = mid

            rows.append((left, i))

        rows.sort()

        return [index for soldiers, index in rows[:k]]