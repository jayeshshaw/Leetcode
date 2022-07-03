class Solution {
public:
    int mod= 1e9+7;
    int dfs(vector<vector<int>>& g,int m, int n, int i, int j,vector<vector<int>> &dp){
        
        if(dp[i][j]!=-1)return dp[i][j]%mod;
        
        int ans=1;
        int d[4][2]={ { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }};
        int ii,jj;
        for(auto x: d){
            ii=i+x[0];
                jj=j+x[1];
                if(ii>=0 && ii<m && jj>=0 && jj<n && g[ii][jj]>g[i][j])
                    ans=ans%mod + dfs(g,m,n,ii,jj,dp)%mod;
            
        }
        return dp[i][j]=ans%mod;
    }
    
    
    int countPaths(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        long long ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                ans=ans%mod+dfs(g,m,n,i,j,dp)%mod;
        }
        return ans%mod;
    }
};