// Algorithm: Binary Search
// 1. Initialize left = 0 and right = nums.size() - 1.
// 2. While left <= right:
//    - Calculate mid = left + (right - left) / 2.
//    - If nums[mid] == target, return mid.
//    - If nums[mid] < target, search the right half
//      by updating left = mid + 1.
//    - Otherwise, search the left half
//      by updating right = mid - 1.
// 3. If the target is not found, return -1.
// Time Complexity: O(log n)
// Space Complexity: O(1)
//here is the code of the problem 
class Solution{
    public:
    int search(vector<int>&nums,int target){
        //intialize 2 pointers
        int left=0;
        int right = nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if (nums[mid]==target){
                return mid;
            }
            //target present at right side 
            if(nums[mid]<target){
                left=mid+1;
            }
            else{
                //target present at left side
                right=mid-1;
            }
        }
        return -1;
    }
};
