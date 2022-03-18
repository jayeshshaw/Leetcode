class Solution {
public:
    int p=0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    grid[i][j]=2;p++;
                    discover_whole_island(grid,i,j);
                    ans=max(ans,p);p=0;
                }
            }
        }
        return ans;
    }
    void discover_whole_island(vector<vector<int>>& grid, int a,int b){
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int new_i=a+dx[i];
            int new_j=b+dy[i];
            if(new_i>=0 && new_j>=0 && new_i<grid.size() && new_j<grid[0].size()&& grid[new_i][new_j]==1){  
                grid[new_i][new_j]=2;p++;
                discover_whole_island(grid, new_i, new_j);
            }
            
        }
    }
};