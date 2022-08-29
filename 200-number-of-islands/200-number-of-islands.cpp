class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    discover_whole_island(i,j,grid);
                }
            }
        }
        return islands;
        
    }
    
    void discover_whole_island( int a,int b, vector<vector<char>>& grid){
        if(a<0 || b<0 || a>=grid.size() || b>=grid[0].size() || grid[a][b]!='1')return;
        
        grid[a][b]='2';
        discover_whole_island(a,b+1,grid);
        discover_whole_island(a+1,b,grid);
        discover_whole_island(a,b-1,grid);
        discover_whole_island(a-1,b,grid);
    }
};