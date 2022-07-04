class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return knapsack(nums,0,dp);
    }
    int knapsack(vector<int>n,int i,vector<int>& dp){
        if(i>n.size()-1)return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        int a=n[i]+knapsack(n,i+2,dp);
        int b=knapsack(n,i+1,dp);
        
        return dp[i]= max(a,b);
    }
    
    
};