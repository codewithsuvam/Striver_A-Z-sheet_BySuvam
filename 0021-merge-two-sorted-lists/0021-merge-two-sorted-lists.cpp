// Algo covers in 5 steps and concept of this question is Two Pointers + Merge.
// 1. Create a dummy node to simplify building the merged linked list.
//    Set tail = &dummy; tail always points to the last node in he result.
// 2. While both lists are non-empty, compare list1->val and list2->val.
// 3. Attach the smaller node to tail->next and move that list's pointer forward.
// 4. Move tail forward. When one list becomes empty, attach the remaining
//    nodes of the other list directly to tail->next.
// 5. Return dummy.next, which points to the head of the merged sorted list.
// Time Complexity: O(n + m), because each node from both lists is processed at most once.
// Space Complexity: O(1) auxiliary space, because we reuse existing nodes and use only a few pointers.

class Solution{
    public:
    ListNode* mergeTwoLists (ListNode*list1, ListNode*list2){
        ListNode dummy(0);
        ListNode* tail=&dummy;
        while(list1 !=nullptr && list2 !=nullptr){
            if (list1->val <=list2->val){
                tail ->next = list1;
                list1 = list1 -> next;
            }
            else{
                tail->next =list2;
                list2 = list2 -> next;
            
            }
            tail = tail ->next;
        }
            if(list1 !=nullptr){
                tail ->next = list1;
            }
            else{
                tail -> next = list2;
            }
            return dummy.next;

        }
    };

