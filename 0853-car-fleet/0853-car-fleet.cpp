// Algo covers in 5 steps and concept of this question is Sorting + Stack + Greedy Approach
// 1. Pair each car's position with its speed and sort the cars by position in descending order.
// 2. Traverse the cars from closest to the target to farthest.
// 3. Calculate each car's time to reach the target using (target - position) / speed.
// 4. If the stack is empty or the current car takes longer than the fleet ahead, push its arrival time as a new fleet. Otherwise, the car joins the fleet ahead.
// 5. Return the number of arrival times stored in the stack, which equals the number of car fleets.
// here is the code of the question 
class Solution{
    public :
    int carFleet (int target, vector<int>&position,vector<int>&speed){
        int n = position.size();
        vector<pair<int,int>> cars;
        for (int i=0;i<n;i++){
            cars.push_back({position[i],speed[i]});       
        }
        sort(cars.begin(), cars.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });
    
        stack<double> st;
        for (int i=0;i<n; i++){
            int pos= cars[i].first;
            int spd=cars[i].second;
            double time = (double)(target-pos)/spd;
            if (st.empty()|| time>st.top()){
                st.push(time);
            }
        }
        return st.size();
        }
    };

    //time complexity O(nlogn) sorting takes O(nlogn) and processing all cars takes O(n)
