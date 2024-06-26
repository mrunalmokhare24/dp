https://leetcode.com/problems/triangle/description/



--------
120. Triangle
Solved
Medium
Topics
Companies
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104





  ---------------
  class Solution {
public:
    int cal(int n,int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(i==n-1)   return triangle[i][j];
        if(dp[i][j]!=-1)   return dp[i][j];
        int d=triangle[i][j];
        d+=cal(n,i+1,j,triangle,dp);
         int d_right=triangle[i][j];
        d_right+=cal(n,i+1,j+1,triangle,dp);
         return dp[i][j]=min(d,d_right);


    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
      //  int n=triangle[0].size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return cal(n,0,0,triangle,dp);
    }
};
