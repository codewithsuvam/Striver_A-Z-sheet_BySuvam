 /*
        Concept Used:
        Binary Search on Partition.
        Algorithm:
        1. Keep nums1 as the smaller array.
        2. Binary Search for a partition in nums1.
        3. Calculate the corresponding partition in nums2
           so the left half has half the total elements.
        4. Check whether both partitions are valid.
        5. If valid, calculate the median.
        6. Otherwise, move the binary search boundaries.
        Time Complexity: O(log(min(m, n)))
        Space Complexity: O(1)
        */
    class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        while (left <= right) {
            int partition1 = left + (right - left) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            int maxLeft1 = (partition1 == 0)
                               ? INT_MIN : nums1[partition1 - 1];

            int minRight1 = (partition1 == m)
                                ? INT_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0)
                               ? INT_MIN : nums2[partition2 - 1];

            int minRight2 = (partition2 == n)
                                ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 1) {
                    return max(maxLeft1, maxLeft2);
                }

                return (max(maxLeft1, maxLeft2) +
                        (double)min(minRight1, minRight2)) / 2.0;
            }
            else if (maxLeft1 > minRight2) {
                right = partition1 - 1;
            }
            else {
                left = partition1 + 1;
            }
        }

        return 0.0;
    }
};