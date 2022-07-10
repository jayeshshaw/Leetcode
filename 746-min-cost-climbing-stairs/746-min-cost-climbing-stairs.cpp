class Solution {
public:
    
    int f(int ind, vector<int> &v,vector<int> &dp){
        if(ind>v.size()-1)return 0;
        if(ind==v.size()-1)return v[ind];
        
        if(dp[ind]!=-1)return dp[ind];
        
        int a=v[ind]+f(ind+1,v,dp),b=INT_MAX;
        b=v[ind]+f(ind+2,v,dp);
        return dp[ind]=min(a,b);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1),dp2(n+1,-1);
        return min(f(0,cost,dp),f(1,cost,dp));
    }
};