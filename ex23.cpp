https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/



---------
714. Best Time to Buy and Sell Stock with Transaction Fee
Solved
Medium
Topics
Companies
Hint
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104


  -------------------
  class Solution {
public:
    int cal(int ind, int buy,int fee, int n, vector<int>& prices, vector<vector<int>>& dp) {
        // Check if the index exceeds the size of prices array
        if (ind >= n) return 0;

        // Check if the value is already computed
        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit;
        if (buy) {
            // Calculate profit if buying
            int take = -prices[ind] + cal(ind + 1, 0,fee, n, prices, dp);
            int nottake = cal(ind + 1, 1, fee,n, prices, dp);
            profit = max(take, nottake);
             
        } else {
            // Calculate profit if not buying (i.e., selling or skipping)
            int sell = prices[ind] + cal(ind + 1, 1,fee, n, prices, dp)-fee;
            int notsell = cal(ind + 1, 0,fee, n, prices, dp);
            profit = max(sell, notsell);
         
        }

        // Store the computed value in dp array
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        // Initialize dp array with -1
        vector<vector<int>> dp(n, vector<int>(2, -1));
        // Start calculating max profit recursively
        return cal(0, 1,fee, n, prices, dp);
    }
};
