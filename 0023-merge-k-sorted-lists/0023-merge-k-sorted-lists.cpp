// Algo covers in 6 steps and concept of this question is Min Heap (Priority Queue).
// 1. Create a min heap to store the current smallest node from each sorted list.
// 2. Push the first node of every non-empty list into the min heap.
// 3. Create a dummy node and a tail pointer to build the merged list.
// 4. While the min heap is not empty:
//    a. Extract the node with the smallest value.
//    b. Attach it to the merged list and move tail forward.
//    c. If that node has a next node, push the next node into the min heap.
// 5. Continue until all nodes have been merged.
// 6. Return dummy->next.
// Time Complexity: O(N log K), where N is the total number of nodes
// and K is the number of sorted lists. Each node is pushed/popped
// from the min heap, whose size is at most K.
// Space Complexity: O(K) for the min heap, excluding the output list.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for (ListNode* node : lists) {
            if (node != nullptr) {
                minHeap.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        tail->next = nullptr;
        return dummy.next;
    }
};