// Algo covers in 6 steps and concept of this question is Two Pointers + Sorted Array
// 1. Initialize two pointers, left at the beginning and right at the end of the array.
// 2. Calculate the sum of the elements at both pointers.
// 3. If the sum equals the target, return their 1-based indices.
// 4. If the sum is smaller than the target, move the left pointer one step right.
// 5. If the sum is greater than the target, move the right pointer one step left.
// 6. Repeat until the target is found and return the answer.
//HERE IS THE CODE OF THE QUESTION 
class Solution{
    public:
    vector<int> twoSum(vector<int>& numbers,int target){
        int left =0;
        int right = numbers.size()-1;
        while (left<right){
            int sum= numbers[left]+numbers[right];
            if (sum==target){
                return{left+1,right+1};
            }
            else if (sum<target){
            left++;
            }
            else{
                right--;
            }
        }
        return{};
    }
};