class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int m=g.size(), n=g[0].size();
        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 and j==0)
                    dp[i][j]=g[i][j];
                else{
                    int down=INT_MAX, right=INT_MAX;
                    if(i>0) down=g[i][j]+dp[i-1][j];
                    if(j>0) right=g[i][j]+dp[i][j-1];
                    
                    dp[i][j]=min(down,right);
                }
            }
        }
        return dp[m-1][n-1];
    }
};