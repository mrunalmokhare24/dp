https://leetcode.com/problems/partition-equal-subset-sum/description/


--------------
416. Partition Equal Subset Sum
Solved
Medium
Topics
Companies
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100


  
  -------------
  class Solution {
public:
    bool cal(int index,vector<int>&nums,int n,int target,vector<vector<int>>&dp){
        //base cases
        if(target==0)    return true;
        if(target<0)   return false;
        if(index>=n)   return false;

        //check if subproblem is already solved or not
        if(dp[index][target]!=-1)  return dp[index][target];

        int take_element=cal(index+1,nums,n,target-nums[index],dp);
         int not_take_element=cal(index+1,nums,n,target,dp);

        //step3 store before returing
        return dp[index][target]=(take_element) || (not_take_element);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int  totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        if(totalsum%2!=0){
            return false;
        }
       int target=totalsum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return cal(0,nums,n,target,dp);
    }
};
  
