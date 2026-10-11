from collections import Counter
import heapq
class Word:
    def __init__(self, word, freq):
        self.word = word
        self.freq = freq
        
    def __lt__(self, other):
        if self.freq != other.freq:
            return self.freq < other.freq
        return self.word > other.word
class Solution:
    def topKFrequent(self, words: list[str], k: int) -> list[str]:
        counts = Counter(words)
        heap = []  
        for word, freq in counts.items():
            heapq.heappush(heap, Word(word, freq))
            if len(heap) > k:
                heapq.heappop(heap)        
        result = []
        while heap:
            result.append(heapq.heappop(heap).word)    
        return result[::-1]
