// Algo covers in 5 steps and concept of this question is Sliding Window + Monotonic Deque.
// 1. Create a deque to store indices of elements in decreasing order of their values.
// 2. Remove indices from the front if they are outside the current window.
// 3. Remove indices from the back while their values are smaller than or equal to the current element.
// 4. Add the current index to the back of the deque.
// 5. Once the window reaches size k, the front index gives the maximum. Add its value to the answer.
//TIME COMPLEXITY O(n) EACH INDEX ENTERS AND LEAVE THE DEQUE AT MOST ONCE 
//SPACE COMPLEXITY O(k) FOR THE DEQUE , EXCLUDING THE OUTPUT ARRAY 
class Solution{
    public:
    vector<int> maxSlidingWindow (vector <int> &nums,int k){
        vector<int>result;
        deque<int>dq;
        for (int right = 0; right<nums.size(); right++){
            if (!dq.empty()&&dq.front()<= right -k){
                dq.pop_front();
            }
            while (!dq.empty()&& nums[dq.back()]<=nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);
            if(right >= k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};