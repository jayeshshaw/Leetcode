class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        int ans=0;
        
        for(int i=0;i<n;i++)dp[i][0]=mat[i][0],ans+=dp[i][0];
        for(int i=0;i<m;i++)dp[0][i]=mat[0][i],ans+=dp[0][i];
        if(dp[0][0]==1)ans--;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==0)continue;
                int val=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                dp[i][j]=val+mat[i][j];
                
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};