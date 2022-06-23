class Solution {
public:
    
    int f(int i, int j, string &a, string &b, vector<vector<int>> &dp){
        if(i<0)return j+1;
        if(j<0)return i+1;

        if(dp[i][j]!=-1)return dp[i][j];

        if( a[i]==b[j])return dp[i][j]=f(i-1,j-1,a,b,dp);
        int repl=1+f(i-1,j-1,a,b,dp);
        int inse=1+f(i,j-1,a,b,dp);
        int del=1+f(i-1,j,a,b,dp);

        return dp[i][j]=min({repl,inse,del});
    }
    
    int minDistance(string a, string b) {
        vector<vector<int>> dp(a.size(),vector<int> (b.size(),-1));
        return f(a.size()-1,b.size()-1,a,b,dp); 
    }
};