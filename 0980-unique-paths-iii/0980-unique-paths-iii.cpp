class Solution {
public:
    int todo=0;
    int dfs(int i, int j, vector<vector<int>> grid,int todo){
        int m=grid.size(),n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1)return 0;
        if(grid[i][j]==2)return todo<0;
        
        
        grid[i][j]=-1;
        todo--;
        int ans=0;
        ans+=dfs(i+1,j,grid,todo)+dfs(i,j+1,grid,todo)+ dfs(i-1,j,grid,todo)+dfs(i,j-1,grid,todo);
        return ans;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int si,sj;todo=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)si=i,sj=j;
                if(grid[i][j]==0)todo++;
            }
        }
        return dfs(si,sj,grid,todo);
    }
};