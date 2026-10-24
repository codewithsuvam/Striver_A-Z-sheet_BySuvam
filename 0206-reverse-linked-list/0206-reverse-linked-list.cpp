// Algo covers in 5 steps and concept of this question is Iterative Pointer Reversal.
// 1. Initialize prev = NULL and curr = head.
// 2. Save the next node using nextNode = curr->next
//    so that the remaining linked list is not lost.
// 3. Reverse the current pointer using curr->next = prev.
// 4. Move prev to curr and curr to nextNode.
//    Repeat steps 2-4 until curr becomes NULL.
// 5. Return prev because it points to the new head of the reversed list.
class Solution{
    public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
};
//t.c O(n) each node is visited exactly once 
//s.c O(1) only 3 pointers are used no extra array or new nodes are created 