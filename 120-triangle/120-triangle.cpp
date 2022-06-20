class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>> &v,vector<vector<int>> &dp){
        if(i==n)return 0;
        
        if( dp[i][j]!=-1)return  dp[i][j];
        
        int dwn=v[i][j]+f(i+1,j,n,v,dp);
        int diag=v[i][j]+f(i+1,j+1,n,v,dp);
        dp[i][j]=min(dwn,diag);
        return dp[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return f(0,0,n,v,dp);
        
        
        
//         for(int j=0;j<v.size();j++)dp[v.size()-1][j]=v[v.size()-1][j];
        
//         for(int i=v.size()-2;i>=0;i--){
//             for(int j=i;j>=0;j--){
//                 int dwn=v[i][j]+f(i+1,j,v,dp);
//                 int diag=v[i][j]+f(i+1,j+1,v,dp);

//                 dp[i][j]= min(dwn,diag);
//             }
//         }
//         return dp[0][0];
    }
    
};