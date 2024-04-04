https://leetcode.com/problems/coin-change/description/



-------------
322. Coin Change
Solved
Medium
Topics
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

  ----------------
  //--Method2
class Solution {
public:
    int cal( int n, int sum, vector<int>& coins, vector<vector<int>>& dp) {
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
          }
        for(int i=1;i<=sum;i++){
            dp[0][i]=INT_MAX-1;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(coins[i-1]<=j){
              dp[i][j]=min(1+(dp[i][j-coins[i-1]]),dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        return dp[n][sum] ;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        int result = cal( n,amount, coins, dp);
        if(result==INT_MAX-1)  return -1;
        else   return result;
    }
};


//---Method2
// class Solution {
// public:

 


//     int solve(vector<int>& coins, int target, int index, vector<vector<int>>& dp){

//         // base case
//         if(target == 0){
//             return 1e9;
//         }

//         if(index == coins.size()){  
//             return 1e9;
//         }

//         if(target < 0){
//             return INT_MAX;
//         }


//         // check dp
//         if(dp[index][target] != -1){
//             return dp[index][target];
//         }


//         // There are 2 possibilities: whether to take the current element or not to take

//         int include = 1 + solve(coins, target-coins[index], index, dp);     

//         int exclude = solve(coins, target, index+1, dp);

//         dp[index][target] = min(include, exclude);
//         return dp[index][target];
//     }


//     int coinChange(vector<int>& coins, int target) {

//         // initialize a 2d vector of coinSize X target and initialize it to -1
//         vector<vector<int>> dp(coins.size()+1, vector<int>(target+1, -1));
        
//         int ans = solve(coins, target, 0, dp);

//         if(ans == 1e9) return -1;
//         return ans;

//     }

// };


