class Solution {
private:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    
    bool dfs(int i, int j ,vector<vector<int>>& grid,vector<vector<int>>& mat){
        int n=grid.size(),m=grid[0].size();
        int cnt1=0,cnt2=0;
        bool ans=true;
        if(mat[i][j]!=1)ans=false;
        grid[i][j]=0;
        
        for(int x=0;x<4;x++){
            int ni=i+delrow[x];
            int nj=j+delcol[x];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                if(mat[ni][nj]==1)cnt1++;
                cnt2++;
                if(!dfs(ni,nj,grid,mat))ans=false;
            }
        }
        return cnt1==cnt2 && ans;
        
    }
    
public:
    int countSubIslands(vector<vector<int>>& mat, vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(dfs(i,j,grid,mat))ans++;
                }
            }
        }
        return ans;
    }
};