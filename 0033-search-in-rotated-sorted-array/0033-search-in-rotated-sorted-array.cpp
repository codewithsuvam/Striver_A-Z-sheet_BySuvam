 /*
        Problem: Search in Rotated Sorted Array
        Concept Used:
        Modified Binary Search.
        At least one half of the rotated array is sorted.
        Identify the sorted half and check whether the
        target lies within its range.
        Algorithm:
        1. Initialize left = 0 and right = nums.size() - 1.
        2. While left <= right:
           - Calculate mid = left + (right - left) / 2.
           - If nums[mid] == target, return mid.
           - If nums[left] <= nums[mid], the left half is sorted:
             - If nums[left] <= target < nums[mid],
               search left half using right = mid - 1.
             - Otherwise, search right half using left = mid + 1.
           - Otherwise, the right half is sorted:
             - If nums[mid] < target <= nums[right],
               search right half using left = mid + 1.
             - Otherwise, search left half using right = mid - 1.
        3. If target is not found, return -1.
        Time Complexity: O(log n)
        Space Complexity: O(1)
        */
        class Solution{
            public:
            int search(vector<int>&nums,int target){
                int left=0;
                int right = nums.size()-1;
                while (left<=right){
                int mid= left+(right-left)/2;
                if (nums[mid]==target){
                    return mid;
                }
                if (nums[left]<=nums[mid]){
                    if (nums[left]<=target && target<nums[mid]){
                        right = mid-1;
                    
                    }
                    else{
                        left=mid+1;
                    }
                }else{
                    if (nums[mid]<target && target<= nums[right]){
                        left=mid+1;
                    }
                    else{
                        right = mid -1;
                    }
                }
            } return -1;
        }
};