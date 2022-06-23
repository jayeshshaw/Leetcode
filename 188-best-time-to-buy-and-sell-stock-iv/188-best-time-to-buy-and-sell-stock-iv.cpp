class Solution {
public:
    
    int f(int i, int b, int k, vector<int> &v,vector<vector<vector<int>>> &dp){
        if(i==v.size() || k==0)return 0;
        
        if(dp[i][b][k]!=-1)return dp[i][b][k];
        
        if(b==1)
            return  dp[i][b][k]= max (-v[i]+f(i+1,0,k,v,dp) , f(i+1,1,k,v,dp));
        else 
            return  dp[i][b][k]= max (v[i]+f(i+1,1,k-1,v,dp) , f(i+1,0,k,v,dp));
    }
    
    int maxProfit(int k, vector<int>& v) {
        vector<vector<vector<int>>> dp(v.size()+1, vector<vector<int>> (2, vector<int> (k+1,-1)));
        return f(0,1,k,v,dp);
    }
};