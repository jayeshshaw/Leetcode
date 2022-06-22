class Solution {
public:
    
    int f(int i, int j, string &s, string &p,vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==p[j])return dp[i][j]= 1+f(i-1,j-1,s,p,dp);
        
        return  dp[i][j]=  max(f(i-1,j,s,p,dp),f(i,j-1,s,p,dp));
    }
    
    int longestCommonSubsequence(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int> (p.size()+1,0));
        // return f(s.size()-1, p.size()-1,s,p,dp);
        
        for(int i=0;i<s.size();i++)dp[i][0]=0;
        for(int j=0;j<p.size();j++)dp[0][j]=0;
        
        for(int i=1;i<s.size()+1;i++){
            for(int j=1;j<p.size()+1;j++){
                if(s[i-1]==p[j-1])dp[i][j]= 1+dp[i-1][j-1];
                else
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[s.size()][p.size()];
    }
};