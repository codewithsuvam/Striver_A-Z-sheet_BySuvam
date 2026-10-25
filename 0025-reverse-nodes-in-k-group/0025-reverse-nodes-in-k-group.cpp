// Algo covers in 6 steps and concept of this question is
// Linked List Pointer Reversal in Groups of K.
// 1. Create a dummy node before the head to simplify reconnection.
// 2. Find the kth node from the group predecessor.
//    If fewer than k nodes remain, stop without reversing them.
// 3. Save the node after the group as groupNext.
// 4. Reverse exactly k nodes using prev, curr, and next pointers.
// 5. Connect the previous group to the new group head,
//    and connect the old group head to groupNext.
// 6. Move the group predecessor to the old group head and repeat.
// Time Complexity: O(N), because each node is visited a constant
// number of times.
// Space Complexity: O(1), because only a constant number of pointers are used and the list is reversed in place.
class Solution{
    public:
    ListNode* reverseKGroup(ListNode* head,int k){
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;
        while (true){
            ListNode* kth =groupPrev;
            for (int i =0; i< k; i++){
                kth = kth->next;
                if (kth==nullptr){
                    return dummy.next;
                }
            }

         ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            ListNode* oldGroupHead = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = oldGroupHead;
        }
    }
};
