// Algo covers in 4 steps and concept of this question is Floyd's Cycle Detection (Slow + Fast Pointers).

// 1. Initialize slow and fast pointers at head.
// 2. While fast and fast->next are not NULL:
//    Move slow by one node and fast by two nodes.
// 3. If slow == fast at any point, a cycle exists, so return true.
// 4. If fast reaches NULL, the list has no cycle, so return false.
// Time Complexity: O(n), because each pointer traverses at most a linear number of nodes.
// Space Complexity: O(1), because only two pointers are used.
class Solution{
    public:
    bool hasCycle(ListNode *head){
        ListNode* slow=head;
        ListNode* fast= head; 
        while (fast!= nullptr&& fast->next !=nullptr){
            slow = slow->next; //move slow one step forward
            fast = fast ->next -> next ;
            //move fast two steps forward 
            if (slow==fast){
                return true;

            }
        }
        return false;
    }
};