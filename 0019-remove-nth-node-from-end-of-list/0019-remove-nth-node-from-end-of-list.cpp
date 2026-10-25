// Algo covers in 4 steps and concept of this question is Two Pointers + Dummy Node.
// 1. Create a dummy node pointing to head and initialize slow and fast at dummy.
// 2. Move fast n + 1 steps forward to maintain the required gap.
// 3. Move slow and fast together until fast becomes NULL.
// 4. Skip the target node using slow->next = slow->next->next.
// Time Complexity: O(n), because the list is traversed at most once.
// Space Complexity: O(1), because only a few pointers are used.
class Solution{
    public:
    ListNode* removeNthFromEnd(ListNode* head,int n){
        ListNode dummy(0);
        dummy.next=head;
        ListNode* slow=&dummy;
        ListNode* fast=&dummy;
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }
        while(fast !=nullptr){
            slow = slow->next;
            fast = fast ->next;

        }
        ListNode* nodeToDelete=slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;
        return dummy.next;
    }
};