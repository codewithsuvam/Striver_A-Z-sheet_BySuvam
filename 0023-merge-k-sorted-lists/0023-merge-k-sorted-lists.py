import heapq

class Solution:
    def mergeKLists(self, lists: list[Optional[ListNode]]) -> Optional[ListNode]:
        ListNode.__lt__ = lambda self, other: self.val < other.val
        heap = []
        for i, l in enumerate(lists):
            if l:
                heapq.heappush(heap, l)
        
        dummy = ListNode(0)
        curr = dummy
        
        while heap:
            node = heapq.heappop(heap)
            curr.next = node
            curr = curr.next
            if node.next:
                heapq.heappush(heap, node.next)
                
        return dummy.next
