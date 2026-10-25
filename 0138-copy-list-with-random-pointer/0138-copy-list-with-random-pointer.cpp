// Algo covers in 3 steps and concept of this question is Hash Map + Deep Copy.
// 1. Traverse the original list and create a copy node for every original node.
// 2. Store each mapping as original node -> copied node in a hash map.
// 3. Traverse again and assign copied next and random pointers using the map.
// Time Complexity: O(n), because the list is traversed twice.
// Space Complexity: O(n), because the hash map stores one mapping per node.
class Solution{
    public:
    Node* copyRandomList(Node* head){
        if(head == nullptr){
            return nullptr;
        }
        unordered_map<Node*,Node*>mp;
            
            Node* curr = head;
            while(curr!=nullptr){
                mp[curr]=new Node(curr->val);
                curr = curr->next;

            }
            curr = head;
            while (curr !=nullptr){
                mp[curr]->next = (curr->next==nullptr)
                ? nullptr
                : mp[curr->next];
                mp[curr]->random = (curr ->random==nullptr)
                ? nullptr
                : mp[curr->random];
                curr= curr->next;

            }
            return mp[head];
}
};