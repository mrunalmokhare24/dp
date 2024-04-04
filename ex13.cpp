https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/




------------
1312. Minimum Insertion Steps to Make a String Palindrome
Solved
Hard
Topics
Companies
Hint
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.






  -------------------
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

    int minInsertions(string s) {
        string str=s;
        int len=s.length();
        reverse(s.begin(),s.end());
        
        int lps=longestCommonSubsequence(s,str);
        return len-lps;
    }
};
