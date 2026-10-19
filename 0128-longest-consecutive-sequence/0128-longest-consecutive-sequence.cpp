// Algo covers in 6 steps and concept of this question is Hash Set + Sequence Detection
// 1. Insert all elements of the array into an unordered set to remove duplicates.
// 2. Iterate through each number in the set.
// 3. If the previous number (num - 1) exists in the set, skip the current number because it is not the start of a sequence.
// 4. If the previous number doesn't exist, consider the current number as the start of a new sequence.
// 5. Count consecutive numbers by checking whether num + 1, num + 2, and so on exist in the set.
// 6. Update the maximum sequence length and return it.
 class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans=0;
        for (int num:st){
            if (st.find(num-1)==st.end()){
                int cur=num;
                int len=1;
                while (st.find(cur+1)!=st.end()){
                    cur++;
                    len++;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};
