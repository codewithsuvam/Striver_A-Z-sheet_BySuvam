// Algo covers in 5 steps and concept of this question is Linked List + Carry.
// 1. Create a dummy node and initialize carry = 0.
// 2. While either list has nodes or carry is non-zero, read both current digits.
// 3. Calculate sum = digit1 + digit2 + carry.
// 4. Create a node with sum % 10 and update carry = sum / 10.
// 5. Return dummy->next as the resulting linked list.
// Time Complexity: O(max(n, m)), where n and m are the lengths of the two lists.
// Space Complexity: O(max(n, m)), for the resulting linked list.
class Solution{
    public:
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* curr=&dummy;
        int carry =0;
        while ( l1 !=nullptr || l2 !=nullptr || carry!=0){
            int x =(l1 != nullptr) ? l1->val : 0;
            int y =(l2 != nullptr) ? l2->val : 0;
            int sum = x+y+carry;
            int digit = sum%10;
            carry = sum/10;
            curr ->next = new ListNode(digit);
            curr = curr->next;
            if (l1 !=nullptr){
                l1=l1->next;
            }
            if(l2 !=nullptr){
                l2= l2->next;
            }
        }
        return dummy.next;
    }
};