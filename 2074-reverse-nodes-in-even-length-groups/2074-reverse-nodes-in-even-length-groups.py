class Solution:
    def reverseEvenLengthGroups(self, head):
        dummy = ListNode(0)
        dummy.next = head

        prev = dummy
        groupSize = 1

        while prev.next:
            # Find actual length of current group
            curr = prev.next
            count = 0

            while curr and count < groupSize:
                curr = curr.next
                count += 1

            # Reverse only if group length is even
            if count % 2 == 0:
                curr = prev.next
                nextNode = curr.next

                for _ in range(count - 1):
                    temp = nextNode.next
                    nextNode.next = curr
                    curr = nextNode
                    nextNode = temp

                first = prev.next
                first.next = nextNode
                prev.next = curr

                prev = first

            else:
                # Move prev to the end of the group
                for _ in range(count):
                    prev = prev.next

            groupSize += 1

        return dummy.next