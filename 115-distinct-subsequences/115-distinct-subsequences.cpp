class Solution {
public:
    
    int f(int i, int j, string &s, string &t,vector<vector<int>> &dp){
        if(j<0)return 1;
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i]==t[j])return dp[i][j]=f(i-1,j,s,t,dp)+f(i-1,j-1,s,t,dp);
        return dp[i][j]=f(i-1,j,s,t,dp);
    }
    
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int> (t.size()+1,-1));
        
        return f(s.size()-1,t.size()-1,s,t,dp);
//         for(int i=0;i<s.size();i++)dp[i][0]=1;
//         for(int j=0;j<t.size();j++)dp[0][j]=0;
        
//         for(int i=1;i<s.size()+1;i++){
//             for(int j=1;j<t.size()+1;j++){
//                 if(s[i-1]==t[j-1]) 
//                     dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
//                 else 
//                     dp[i][j]=dp[i-1][j];
//             }
//         }
//         return dp[s.size()][t.size()];
    }
};