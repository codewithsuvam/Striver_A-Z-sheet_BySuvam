// Algo covers in 5 steps and concept of this question is Monotonic Stack
// 1. Create an answer array initialized with 0 and an empty stack to store indices of days.
// 2. Traverse the temperatures array from left to right.
// 3. While the stack is not empty and the current temperature is greater than the temperature at the index on top of the stack, pop that index.
// 4. For each popped index, calculate the waiting days as current index minus the popped index, then push the current index onto the stack.
// 5. Return the answer array; days without a warmer future temperature remain 0.
//here is the code of this question !! 
class Solution{
    public:
    vector<int> dailyTemperatures (vector<int>& temperatures){
        int n= temperatures.size();
        // store the waitingg days for each day
        vector <int> ans(n,0);
        //store indices of days with unresolved warmer temp 
        stack <int> st;
        for (int i=0; i <n ; i++){
            //curr temp is warmer than the temp 
            //at the index on top of the stack ! 
            while (!st.empty()&& temperatures[i]> temperatures[st.top()]){
                //get the prev day whose ans is known
                int prevIndex=st.top();
                st.pop();
                // cal how many DAYS we waited
                ans[prevIndex]=i-prevIndex;
            }
            st.push(i); //current day index store 
        }
        return ans;// unresolved days already have ans= 0
    }
};
//time complexity O(n) each index is pushed onto the stack once and popped at most once , so the total no of stack operation is linear !! 
