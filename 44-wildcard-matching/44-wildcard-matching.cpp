class Solution {
public:
    bool f(int i, int j, string &a, string &b,vector<vector<int>> &dp){
    if(j<0 && i<0)return true;
    if(i<0 && j>=0)return false;
    if(i>=0 && j<0){
        for(int ind=0;ind<=i;ind++){if(a[ind]!='*')return false;}
        return true;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    if(a[i]==b[j] || a[i]=='?')return dp[i][j]=f(i-1,j-1,a,b,dp);
    
    
    if(a[i]=='*')return dp[i][j]=(f(i-1,j,a,b,dp) || f(i,j-1,a,b,dp));

    return dp[i][j]=false;
    

}
    
    bool isMatch(string a, string b) {
        string x=a;
        a=b;b=x;
        vector<vector<int>> dp(a.size(),vector<int> (b.size(),-1));
        return f(a.size()-1,b.size()-1,a,b,dp);
    }
};