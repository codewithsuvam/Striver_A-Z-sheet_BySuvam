// Algo covers in 6 steps and concept of this question is Sorting + Two Pointers + Duplicate Handling
// 1. Sort the array to arrange numbers in increasing order.
// 2. Iterate through the array and fix one number as the first element of the triplet.
// 3. Skip duplicate fixed numbers to avoid repeating triplets.
// 4. Initialize left and right pointers to find the remaining two numbers.
// 5. Calculate the triplet sum; move left if the sum is smaller than 0, move right if it is greater than 0, and store the triplet if the sum is 0.
// 6. Skip duplicate left and right values after finding a triplet, continue searching, and return all unique triplets.
//here is the code of the question 
class Solution{
    public:
    vector<vector<int>> threeSum(vector<int>&nums){
        vector<vector<int>> result;
        int n= nums.size();
        sort (nums.begin(),nums.end());
        for (int i=0; i<n-2;i++){
    if(i>0 && nums [i]== nums[i-1]){
        continue;

    }
    int left=i+1;
    int right=n-1;
    while (left<right){
        int sum= nums [i]+ nums [left]+ nums [right];
        if (sum==0){
            result.push_back({nums[i],nums[left],nums[right]});
            left++;
            right--;
            while (left<right && nums[left]== nums [left-1]){
                left++;
            }
            while (left<right && nums[right]== nums[right +1 ]){
                right--;
            }
    }
    else if (sum<0){
        left++;

    }
    else{
        right--;
    }
        }
    }
    return result;
    }
};  // time complexity is O (n^2) sorting ke baad outer loop aur 2 pointers traversal 