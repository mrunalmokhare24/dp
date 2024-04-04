https://leetcode.com/problems/minimum-path-sum/description/


---------
64. Minimum Path Sum
Solved
Medium
Topics
Companies
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200






  -------------
  class Solution {
public:
   int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)  dp[i][j]=grid[0][0];
                else{
                       int  up=grid[i][j];
                int  left=grid[i][j];
                if(i>0){
                    up+=dp[i-1][j];
                }else{
                    up=INT_MAX;
                }

                  if(j>0){
                    left+=dp[i][j-1];
                } else{
                    left=INT_MAX;
                }
                dp[i][j]=min(up,left);
                }
                
                
            }
        }
        return dp[m-1][n-1];
    }
};
