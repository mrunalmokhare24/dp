https://leetcode.com/problems/coin-change-ii/description/


--------
518. Coin Change II
Solved
Medium
Topics
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000


  ------------
  class Solution {
public:int cal(int index, int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // Base cases
        if (amount == 0) return 1;
        if(amount<0)  return 0; // Successfully made change for the target amount
        if (index >= n) return 0; // Invalid combination of coins
 // Invalid combination of coins
        
        // Check if subproblem is already solved or not
        if (dp[index][amount] != -1) return dp[index][amount];

        // Include the current coin in the sum
        int pick =cal(index, n,  amount - coins[index], coins, dp);
        // Exclude the current coin from the sum
        int not_pick = cal(index + 1, n,  amount, coins, dp);

        // Store the result before returning
        return dp[index][amount] = (pick + not_pick);
    }

    int change(int amount, vector<int>& coins) {
          int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int result = cal(0, n,amount, coins, dp);
       return result;
    }
};
  
