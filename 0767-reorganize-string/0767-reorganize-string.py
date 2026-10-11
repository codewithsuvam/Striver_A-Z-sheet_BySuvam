import heapq
from collections import Counter

class Solution:
    def reorganizeString(self, s: str) -> str:
        freq = Counter(s)

        if max(freq.values()) > (len(s) + 1) // 2:
            return ""

        max_heap = [(-count, char) for char, count in freq.items()]
        heapq.heapify(max_heap)

        result = []
        prev_count, prev_char = 0, ''

        while max_heap:
            count, char = heapq.heappop(max_heap)
            result.append(char)

            if prev_count < 0:
                heapq.heappush(max_heap, (prev_count, prev_char))

            count += 1

            prev_count, prev_char = count, char

        return ''.join(result)