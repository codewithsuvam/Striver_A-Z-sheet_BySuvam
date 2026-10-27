// Algo covers in 5 steps and concept of this question is Greedy.
// 1. Initialize totalTank, currentTank, and start to 0.
// 2. Traverse each station and calculate gain = gas[i] - cost[i].
// 3. Add gain to both totalTank and currentTank.
// 4. If currentTank becomes negative, set start = i + 1
//    and reset currentTank = 0.
// 5. Return -1 if totalTank < 0; otherwise return start.
// TC: O(n) - Each station is processed exactly once.
// SC: O(1) - Only a constant number of variables are used.
class Solution{
    public:
    int canCompleteCircuit(vector<int>&gas,vector<int>&cost){
        int totalTank=0;
        int currentTank=0;
        int start=0;
        for(int i=0; i<gas.size();i++){
            int gain = gas [i]- cost[i];
            totalTank+=gain;
            currentTank+=gain;
            if(currentTank<0){
                start= i+1;
                currentTank=0;
            }
        }
        return totalTank <0 ? -1 : start; // if total petrol is insufficient then -1 otherwise returns start! 
    }
};