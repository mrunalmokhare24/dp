https://leetcode.com/problems/shortest-common-supersequence/description/

---------
1092. Shortest Common Supersequence 
Solved
Hard
Topics
Companies
Hint
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters


-------------
  class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        //--lcs code
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) {
                    dp[i][j]=0;
                } 
                else if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        string ans="";
        int i=n;
        int j=m;
        while(i>0 && j>0){
             if(str1[i-1]==str2[j-1]){
                //add once the common element
                ans+=str1[i-1];
                i--;
                j--;
             }
             else if(dp[i-1][j]>dp[i][j-1]){
                //up vala max hai..to left wala  outoff karo
                ans+=str1[i-1];
                i--;
             }
             else{
                 //left vala max hai..to up wala  outoff karo
                ans+=str2[j-1];
                j--;
             }
        }

        //check for remaining elements in str1 or in str2 both
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
         while(j>0){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};









