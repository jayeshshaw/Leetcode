class Solution {
private:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    
    void dfs1(int i, int j ,vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        
        grid[i][j]=0;
        
        for(int x=0;x<4;x++){
            int ni=i+delrow[x];
            int nj=j+delcol[x];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1)dfs1(ni,nj,grid);
        }
        
        
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==1)dfs1(i,0,grid);
            if(grid[i][m-1]==1)dfs1(i,m-1,grid);
        }
        
        for(int i=0;i<m;i++){
            if(grid[0][i]==1)dfs1(0,i,grid);
            if(grid[n-1][i]==1)dfs1(n-1,i,grid);
        }
        
        int islands=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1){
                    islands++;
                }
            }
        }
        return islands;
    }
};