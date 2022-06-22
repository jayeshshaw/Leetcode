class Solution {
public:
    
    int f(int i, int j, string &s, string &p,vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==p[j])return dp[i][j]= 1+f(i-1,j-1,s,p,dp);
        
        return  dp[i][j]=  max(f(i-1,j,s,p,dp),f(i,j-1,s,p,dp));
    }
    
    int longestCommonSubsequence(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int> (p.size(),-1));
        return f(s.size()-1, p.size()-1,s,p,dp);
    }
};