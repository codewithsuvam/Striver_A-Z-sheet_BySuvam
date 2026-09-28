class Solution:
    def reverseKGroup(self, head, k):
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        while True:
            # Find the kth node
            kth = prev
            for _ in range(k):
                kth = kth.next
                if kth is None:
                    return dummy.next

            # Store the next group
            groupNext = kth.next

            # Reverse the group
            prevNode = groupNext
            curr = prev.next

            while curr != groupNext:
                temp = curr.next
                curr.next = prevNode
                prevNode = curr
                curr = temp

            # Connect previous part to reversed group
            temp = prev.next
            prev.next = kth
            prev = temp