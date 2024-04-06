https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/


-------
122. Best Time to Buy and Sell Stock II
Solved
Medium
Topics
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104



--------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
         //int buy=1;
          long profit;
           
      vector<vector<long>>dp(n+1,vector<long>(2,0));
    //  dp[n][0] = dp[n][1] = 0;
      for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
                   if(buy){
            //can buy the stock
            int take_stock=-prices[ind]+dp[ind+1][0];
            int not_take_stock=0+dp[ind+1][1];

           profit=max(take_stock,not_take_stock);
        }
        else{
            //can sell the stock
            int sell_stock=prices[ind]+dp[ind+1][1];
            int not_sell_stock=0+dp[ind+1][0];

            profit=max(sell_stock,not_sell_stock);
        }
         dp[ind][buy]=profit;

        }
         
      }
      return dp[0][1];
    }
};


// class Solution {
// public:
//     int ans(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp,int n){
        
//         //base cases
//         if(ind==n)   return 0;

//         if(dp[ind][buy]!=-1)  return dp[ind][buy];
//          int profit=0;
//         if(buy){
//             //can buy the stock
//             int take_stock=-prices[ind]+ans(ind+1,0,prices,dp,n);
//             int not_take_stock=0+ans(ind+1,1,prices,dp,n);

//            profit=max(take_stock,not_take_stock);
//         }
//         else{
//             //can sell the stock
//             int sell_stock=prices[ind]+ans(ind+1,1,prices,dp,n);
//             int not_sell_stock=0+ans(ind+1,0,prices,dp,n);

//             profit=max(sell_stock,not_sell_stock);
//         }
//         return dp[ind][buy]=profit;


//     }
//     int maxProfit(vector<int>& prices) {
//         //infinite trasactions possible here
//         int n=prices.size();
//         vector<vector<int>>dp(n,vector<int>(2,-1));
//         return ans(0,1,prices,dp,n);
//     }
// };
