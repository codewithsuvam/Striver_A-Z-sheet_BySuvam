/*
        Problem: Koko Eating Bananas
        Concept Used:
        Binary Search on Answer.
        Search for the minimum eating speed that allows
        Koko to finish all banana piles within h hours.
        Algorithm:
        1. Set left = 1 and right = maximum pile size.
        2. While left < right:
           - Calculate mid = left + (right - left) / 2.
           - Calculate total hours required at speed mid.
           - If hours <= h, mid is a valid speed;
             search for a smaller speed using right = mid.
           - Otherwise, increase the speed using left = mid + 1.
        3. Return left as the minimum valid eating speed.

        Time Complexity: O(n * log(maxPile))
        Space Complexity: O(1)
        */
class Solution{
    public:
    int minEatingSpeed(vector<int>&piles,int h){
        int left =1;
        int right = *max_element(piles.begin(), piles.end());
        while (left<right){
            int mid = left+(right - left)/2;
            long long hours =0;
            for (int pile:piles){
                hours+= (pile+mid-1)/mid;

            }
            if (hours<=h){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};

