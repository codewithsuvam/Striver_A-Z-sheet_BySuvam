// Algo covers in 3 steps and concept of this question is Middle + Reverse + Merge.
// 1. Use slow and fast pointers to find the middle of the linked list.
// 2. Split the list at the middle and reverse the second half.
// 3. Merge both halves alternately: first node, last node, second node, second-last node.
// Time Complexity: O(n), because finding the middle, reversing, and merging take linear time.
// Space Complexity: O(1), because we use only pointers and do not create extra nodes.
class Solution{
    public:
    void reorderList(ListNode* head){
        if (head == nullptr || head -> next == nullptr){
            return ;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast  -> next != nullptr && fast->next->next !=nullptr){
            slow = slow ->next;
            fast = fast ->next->next;

        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode*prev = nullptr;
        ListNode*curr = second;
        while (curr !=nullptr){
            ListNode*nextNode= curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        second = prev;
        ListNode* first=head;
        while(second!=nullptr){
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;
            first ->next =second;
            second ->next = firstNext;
            first=firstNext;
            second=secondNext;
        }
    }
};