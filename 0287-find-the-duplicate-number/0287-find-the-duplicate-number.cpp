// Algo covers in 4 steps and concept of this question is Floyd's Cycle Detection.
// 1. Initialize slow and fast at nums[0].
// 2. Move slow one step and fast two steps until they meet inside the cycle.
// 3. Reset slow to nums[0], keeping fast at the meeting point.
// 4. Move both one step at a time; their meeting point is the duplicate number.
// Time Complexity: O(n), because the pointers traverse the array linearly.
// Space Complexity: O(1), because only two pointers are used.
class Solution{
    public:
    int findDuplicate(vector<int>&nums){
        int slow = nums [0];
        int fast = nums [0];
        do {
            slow = nums [slow];
            fast = nums [ nums [ fast ]];
        }
        while (slow != fast);
        slow = nums [0];
        while(slow != fast ){
            slow=nums [ slow ];
            fast = nums [ fast] ;

        }
        return slow ;
        }
    };
