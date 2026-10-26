// Algo covers in 4 steps and concept of this question is Greedy / Kadane's Algorithm.

// 1. Initialize currentSum and maxSum with the first element.
// 2. Traverse the array starting from the second element.
// 3. Either start a new subarray at the current element
//    or extend the previous subarray using max(nums[i], currentSum + nums[i]).
// 4. Update maxSum with the best sum found and return maxSum.
class Solution{
    public:
    int maxSubArray(vector<int>&nums){
        int currentSum = nums[0];
        int maxSum = nums[0];
        for (int i =1; i<nums.size();i++){
            currentSum = max(nums[i],currentSum+ nums[i]);
            maxSum= max(maxSum,currentSum);

        }
        return maxSum;
    }
};
//Time: (O(n)) — We traverse the array once, processing each element in constant time.
//Extra space: (O(1)) — We use only two variables, regardless of the input size.