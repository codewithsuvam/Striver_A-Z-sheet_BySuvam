class Solution:
    def rotateRight(self, head, k):
        if not head or not head.next or k == 0:
            return head

        # Find length and last node
        length = 1
        tail = head

        while tail.next:
            tail = tail.next
            length += 1

        # Avoid unnecessary rotations
        k = k % length

        if k == 0:
            return head

        # Make the list circular
        tail.next = head

        # Find new tail
        steps = length - k
        newTail = head

        for _ in range(steps - 1):
            newTail = newTail.next

        # New head is after new tail
        newHead = newTail.next

        # Break the circle
        newTail.next = None

        return newHead