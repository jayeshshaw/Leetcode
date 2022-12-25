class Solution {
public:
    int m,n;
    vector<vector<vector<int>>> dp;
    int f(int i, int j1, int j2, vector<vector<int>>& grid){
        if(i>=m || j1<0 || j1>=n || j2<0 || j2>=n)return 0;
        if(i==m-1){
            int ans=grid[i][j1];
            if(j1!=j2)ans+= grid[i][j2];
            return ans;
        }
        
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        
        int ans=grid[i][j1];
        if(j1!=j2)ans+= grid[i][j2];
        int mx=0;
        for(int x=-1;x<2;x++){
            for(int y=-1;y<2;y++){
                mx=max(mx,f(i+1,j1+x,j2+y,grid));
            }
        }
        return dp[i][j1][j2]=ans+mx;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        dp.resize(m,vector<vector<int>> (n, vector<int> (n,-1)));
        return f(0,0,n-1,grid);
    }
};