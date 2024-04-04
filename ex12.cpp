https://leetcode.com/problems/longest-palindromic-subsequence/description/



---------
516. Longest Palindromic Subsequence
Solved
Medium
Topics
Companies
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.

--------------
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

    int longestPalindromeSubseq(string s) {
         string reversed_s = s;
reverse(s.begin(), s.end());
return longestCommonSubsequence(s, reversed_s);
    }
};
