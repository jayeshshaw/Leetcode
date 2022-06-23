class Solution {
public:
    int f(int i, vector<int> &v, int buy, int moves, vector<vector<vector<int>>> &dp){

        if(i==v.size() || moves==0)return 0;
        
        if(dp[i][buy][moves]!=-1)return dp[i][buy][moves];

        if(buy==1)
            return dp[i][buy][moves]= max(-v[i]+f(i+1,v,0,moves,dp),f(i+1,v,1,moves,dp));
        else
            return dp[i][buy][moves]= max(v[i]+f(i+1,v,1,moves-1,dp), f(i+1,v,0,moves,dp));
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (2,vector<int> (3,-1)));
        return f(0,prices,1,2,dp);
    }
};