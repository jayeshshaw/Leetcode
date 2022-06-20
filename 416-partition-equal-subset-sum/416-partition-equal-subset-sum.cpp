class Solution {
public:
    bool f(int i,int t, vector<int> &nums,vector<vector<int>> &dp){
        if(i==0)return nums[0]==t;
        
        if(dp[i][t]!=-1)return dp[i][t];
        
        bool a=0;
        if(t>=nums[i])a=f(i-1,t-nums[i],nums,dp);
        bool b=f(i-1,t,nums,dp);
        return dp[i][t]= (a || b);
    }
    
    bool subSetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (k+1,-1));
        return f(n-1,k,nums,dp);
    }
    
    bool canPartition(vector<int>& nums) {
        int a=0;
        for(auto i: nums)a+=i;
        if(a%2!=0)return false;
        int target=a/2;
        
        return subSetSum(nums,target);
    }
};