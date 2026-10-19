// Algo covers in 6 steps and concept of this question is Prefix Product + Suffix Product
// 1. Create a result array of size n, initialized with 1.
// 2. Traverse from left to right, storing the product of all elements to the left of each index.
// 3. Update the running prefix product after processing each index.
// 4. Traverse from right to left, maintaining the product of all elements to the right.
// 5. Multiply each result element by the running suffix product and update the suffix product.
// 6. Return the result array.
//here is the code 
class Solution{
    public:
    vector<int> productExceptSelf(vector<int>&nums){
        int n=nums.size();
        vector<int>result(n,1);
        int prefix=1;
        for (int i=0; i<n ;i++){
            result[i]=prefix;
            prefix *=nums[i];
        }
        int suffix =1;
        for (int i=n-1; i>=0;i--){
            result[i]*=suffix;
            suffix*=nums[i];
        }
        return result;
    }
};