from typing import List

class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        i = 0
        j = 0
        result = []

        while i < len(firstList) and j < len(secondList):
            # Find intersection
            start = max(firstList[i][0], secondList[j][0])
            end = min(firstList[i][1], secondList[j][1])

            # If they overlap
            if start <= end:
                result.append([start, end])

            # Move the interval which ends first
            if firstList[i][1] < secondList[j][1]:
                i += 1
            else:
                j += 1

        return result