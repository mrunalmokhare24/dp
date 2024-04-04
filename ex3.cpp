https://leetcode.com/problems/house-robber/

------------
 House Robber
Solved
Medium
Topics
Companies
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400


--------------
class Solution {
public:

    //---Method1
    int cal(int ind,vector<int>&nums,vector<int>&dp){
        if(ind==0) {
            return nums[ind];
        }
        if(ind<0)  return 0;
        if(dp[ind]!=-1)   return dp[ind];
        int peak_element=nums[ind]+cal(ind-2,nums,dp);
        int notpeak_element=cal(ind-1,nums,dp);
        int maxi=max(peak_element,notpeak_element);

        return dp[ind]=maxi;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return cal(n-1,nums,dp);

    }


    //---Method2
      int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
        int peak_element=nums[i];
        if(i>1)  peak_element+=dp[i-2];
        int notpeak_element=dp[i-1];
        dp[i]=max(peak_element,notpeak_element);

        }
        return dp[n-1];

    }


      //---Method3
      int rob(vector<int>& nums) {
        int n=nums.size();
      int prev1=nums[0];
      int prev2=0;
        for(int i=1;i<n;i++){
        int peak_element=nums[i];
        if(i>1)  peak_element+=prev2;;
        int notpeak_element=prev1;
        int curr=max(peak_element,notpeak_element);
        prev2=prev1;
        prev1=curr;
        }
        return prev1;

    }
};
