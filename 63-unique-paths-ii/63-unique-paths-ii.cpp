class Solution {
public:
    vector<vector<int>> dp;
    int m,n;
    int travel(vector<vector<int>>& g,int i,int j){
        
        if(i>=m || j>=n)return 0;
        if(g[i][j]==1)return 0;
        if(i==m-1 && j==n-1)return 1;
        
        
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=travel(g,i+1,j)+travel(g,i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        m=g.size();
        n=g[0].size();
        // if(g[n-1][n-1]==1)return 0;
        dp.resize(m,vector<int> (n,-1));
        return travel(g,0,0);
    }
};