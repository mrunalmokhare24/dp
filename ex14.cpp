https://leetcode.com/problems/delete-operation-for-two-strings/description/


-------------
583. Delete Operation for Two Strings
Solved
Medium
Topics
Companies
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters





------------------

  class Solution {
public:
       int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }else{
                    //dp[i - 1][j] represents the length of the longest common subsequence obtained by excluding the i-th character of text1.
                    //dp[i][j - 1] represents the length of the longest common subsequence obtained by excluding the j-th character of text2.
                         dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
    
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
      
        int length1=word1.length();  
         int length2=word2.length();  
        int lps=longestCommonSubsequence(word1,word2);
        return ((length1-lps)+(length2-lps));
    }
};
  
