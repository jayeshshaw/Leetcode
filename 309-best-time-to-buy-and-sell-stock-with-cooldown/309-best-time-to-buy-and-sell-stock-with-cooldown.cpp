class Solution {
public:
    int f(int i, int b, vector<int> &v,vector<vector<int>> &dp){
        if(i>=v.size())return 0;
        
        if(dp[i][b]!=-1)return dp[i][b];
        
        if(b==1)
            return  dp[i][b]= max (-v[i]+f(i+1,0,v,dp) , f(i+1,1,v,dp));
        else 
            return  dp[i][b]= max (v[i]+f(i+2,1,v,dp) , f(i+1,0,v,dp));
    }
    
    int maxProfit(vector<int>& v) {
        vector<vector<int>> dp(v.size()+1, vector<int> (2,-1));
        return f(0,1,v,dp);
    }
};