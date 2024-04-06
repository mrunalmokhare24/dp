https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/


------------
188. Best Time to Buy and Sell Stock IV
Attempted
Hard
Topics
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000



  ---------------------
  class Solution {
public:
    // int cal(int ind,int buy,int cap,int n,vector<int>&prices,vector<vector<vector<int>>>&dp){
    //         if(ind==n)  return 0;
    //         if(cap==0)  return 0;

    //         if (dp[ind][buy][cap] != -1)
    //     return dp[ind][buy][cap];


    //        int profit;
    //         if(buy){
    //             int take=-prices[ind]+cal(ind+1,0,cap,n,prices,dp);
    //             int nottake=0+cal(ind+1,1,cap,n,prices,dp);

    //             profit=max(take,nottake);

    //         }else{
    //              int sell=prices[ind]+cal(ind+1,1,cap-1,n,prices,dp);
    //             int notsell=0+cal(ind+1,0,cap,n,prices,dp);

    //             profit=max(sell,notsell);
    //         }

    //         return dp[ind][buy][cap]=profit;

    // }
    int maxProfit(int K,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(K+1,0)));
        int profit;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=K;cap++){
                      
            if(buy){
                int take=-prices[ind]+dp[ind+1][0][cap];
                int nottake=0+dp[ind+1][1][cap];

                 dp[ind][buy][cap]=max(take,nottake);

            }else{
                 int sell=prices[ind]+dp[ind+1][1][cap-1];
                int notsell=0+dp[ind+1][0][cap];

                 dp[ind][buy][cap]=max(sell,notsell);
            }

           
                }
            }
        }
        return dp[0][0][K];
    }
};
