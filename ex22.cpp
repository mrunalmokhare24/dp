https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/


-------------
309. Best Time to Buy and Sell Stock with Cooldown
Solved
Medium
Topics
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000








  ----------------
  class Solution {
public:
    int cal(int ind, int buy, int n, vector<int>& prices, vector<vector<int>>& dp) {
        // Check if the index exceeds the size of prices array
        if (ind >= n) return 0;

        // Check if the value is already computed
        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit;
        if (buy) {
            // Calculate profit if buying
            int take = -prices[ind] + cal(ind + 1, 0, n, prices, dp);
            int nottake = cal(ind + 1, 1, n, prices, dp);
            profit = max(take, nottake);
        } else {
            // Calculate profit if not buying (i.e., selling or skipping)
            int sell = prices[ind] + cal(ind + 2, 1, n, prices, dp);
            int notsell = cal(ind + 1, 0, n, prices, dp);
            profit = max(sell, notsell);
        }

        // Store the computed value in dp array
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // Initialize dp array with -1
        vector<vector<int>> dp(n, vector<int>(2, -1));
        // Start calculating max profit recursively
        return cal(0, 1, n, prices, dp);
    }
};

  
