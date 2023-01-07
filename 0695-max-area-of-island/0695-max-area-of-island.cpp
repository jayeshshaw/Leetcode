class Solution {
private:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    
    int dfs(int i, int j, vector<vector<int>> &grid){
        
        grid[i][j]=2;
        int cnt=1;
        int n=grid.size(),m=grid[0].size();
        
        for(int x=0;x<4;x++){
            int ni=i+delrow[x];
            int nj=j+delcol[x];
            
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1)cnt+=dfs(ni,nj,grid);
            
        }
        return cnt;
    }
        
        
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int cnt=dfs(i,j,grid);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};