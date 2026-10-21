/*
        Problem: Find Minimum in Rotated Sorted Array
        Concept Used:
        Binary Search on a rotated sorted array.
        Compare the middle element with the rightmost element
        to determine which half contains the minimum.
        Algorithm:
        1. Initialize left = 0 and right = nums.size() - 1.
        2. While left < right:
           - Calculate mid = left + (right - left) / 2.
           - If nums[mid] > nums[right], minimum lies
             in the right half: left = mid + 1.
           - Otherwise, minimum lies at mid or to its left:
             right = mid.
        3. Return nums[left].
        Time Complexity: O(log n)
        Space Complexity: O(1)
        */
        class Solution{
            public:
            int findMin(vector<int>&nums){
            int left=0;
            int right= nums.size()-1;
            while(left<right){
                int mid= left+(right-left)/2;
                if(nums[mid]>nums[right]){
                    left=mid+1;
                }
                else {
                    right=mid;
                }
            }
            return nums[left];
        }
        };