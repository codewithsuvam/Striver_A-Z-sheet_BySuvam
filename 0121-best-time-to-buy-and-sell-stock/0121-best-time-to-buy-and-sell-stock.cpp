/*
Concept Used:
Sliding Window / Two Pointers.

Algorithm:
1. Initialize left = 0 (buy day) and right = 1 (sell day).
2. Traverse prices using right.
3. If prices[left] < prices[right]:
   - Calculate profit = prices[right] - prices[left].
   - Update maxProfit if profit is greater.
4. Otherwise, update left = right because
   the current price is lower and better for buying.
5. Increment right and repeat.
6. Return maxProfit.

Time Complexity: O(n)
Each element is visited at most once.

Space Complexity: O(1)
Only a constant number of variables are used.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int maxProfit = 0;

        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
                int profit = prices[right] - prices[left];
                maxProfit = max(maxProfit, profit);
            } else {
                left = right;
            }

            right++;
        }

        return maxProfit;
    }
};