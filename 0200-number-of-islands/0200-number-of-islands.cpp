class Solution {
    
private:
    
    void dfs(vector<vector<char>>& matrix,int i,int j){
        int m=matrix.size();
        int n=matrix[0].size();
        if(i<0 || i>=m ||j<0 || j>=n || matrix[i][j]!='1')return;
        
        matrix[i][j]='2';
        dfs(matrix,i+1,j);
        dfs(matrix,i,j+1);
        dfs(matrix,i-1,j);
        dfs(matrix,i,j-1);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        vector<vector<char>> matrix=grid;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    islands++;
                    dfs(matrix,i,j);
                }
           }
        }
        return islands;
    }
};