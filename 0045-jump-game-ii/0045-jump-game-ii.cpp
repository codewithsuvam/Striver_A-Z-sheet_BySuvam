// Algo covers in 5 steps and concept of this question is Greedy.

// 1. Initialize jumps, currentEnd, and farthest to 0.
// 2. Traverse the array up to the second-last index.
// 3. Update farthest = max(farthest, i + nums[i]).
// 4. When i reaches currentEnd, increment jumps and
//    update currentEnd = farthest.
// 5. Return jumps as the minimum number of jumps needed.
class Solution{
    public:
    int jump(vector<int>& nums){
        int jumps=0;
        int currentEnd=0;
        int farthest=0;
        for (int i=0;i<nums.size()-1;i++){
            farthest = max(farthest,i+nums[i]);
            if(i==currentEnd){
                jumps++;
                currentEnd= farthest;
            }
        }
        return jumps;
    }
};
// time complexity= O(n) we traverse the array once 
// space complexity = O(1) only three variables are used 