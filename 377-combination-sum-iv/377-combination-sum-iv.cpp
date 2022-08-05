class Solution {
public:
    int f(int i, int sm,vector<int> &v, int &t, vector<vector<int>> &dp){
        
        if(sm==t){return 1;}
        if(i==v.size())return 0;
        
        if(dp[i][sm]!=-1)return dp[i][sm];
        
        int a=0,b=0;
        
        if(sm+v[i]<=t) a=f(0,sm+v[i],v,t,dp);
        b=f(i+1,sm,v,t,dp);
        return dp[i][sm]= a+b;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int> (target+1,-1));
        return f(0,0,nums,target,dp);
    }
};