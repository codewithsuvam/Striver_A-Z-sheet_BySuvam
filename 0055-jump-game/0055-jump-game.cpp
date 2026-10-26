//formula used maxReach = max(maxReach,i + nums[i])
// Algo covers in 4 steps and concept of this question is Greedy.

// 1. Initialize maxReach = 0, the farthest index reachable so far.
// 2. Traverse the array from index 0 to the last index.
// 3. If i > maxReach, return false because the current index is unreachable.
// 4. Update maxReach = max(maxReach, i + nums[i]).
//    If the last index is reachable after traversal, return true.
class Solution{
    public:
    bool canJump(vector<int>&nums){
        int maxReach=0;
        for (int i = 0; i< nums.size();i++){
            if (i>maxReach){
                return false;
            }
            maxReach =max(maxReach, i+nums[i]);
        }
        return true;
    }
};
//Time: (O(n)) — Each array element is visited once.
//Extra space: (O(1)) — Only the maxReach variable is maintained.