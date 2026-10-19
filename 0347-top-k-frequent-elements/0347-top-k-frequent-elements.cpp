// algo for the code in just 6 steps 
// 1. Create a hash map to count the frequency of each element.
// 2. Use a min heap to store elements along with their frequencies.
// 3. Push each element and its frequency into the min heap.
// 4. If the heap size exceeds k, remove the element with the lowest frequency.
// 5. Extract the remaining k elements from the heap and store them in the result.
// 6. Return the result.
class Solution{
    public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int,int> freq;
        for (int num: nums){
            freq[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (auto&entry: freq){
            pq.push({entry.second,entry.first});
            if(pq.size()> k){
                pq.pop();
            }
        }
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};