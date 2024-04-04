https://leetcode.com/problems/edit-distance/



------------
  72. Edit Distance
Solved
Medium
Topics
Companies
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters





-------------
class Solution {
public:
    int ans(int i,int j,string word1,string word2,vector<vector<int>>&dp){
        //--base cases
        if(j<0)   return i+1;
        if(i<0)    return j+1;

        if(dp[i][j]!=-1)  return dp[i][j];

        if(word1[i]==word2[j]){
            return ans(i-1,j-1,word1,word2,dp);
        }
        else{
            //do 3  operation 
            //Insert--1+f(i,j-1)
            //Delete 1+f(i-1,j)
            //replace 1+f(i-1,j-1)

            return dp[i][j]=min(1+ans(i,j-1,word1,word2,dp),min( (1+ans(i-1,j,word1,word2,dp)),1+ans(i-1,j-1,word1,word2,dp) ));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return ans(n-1,m-1,word1,word2,dp);
    }
};
