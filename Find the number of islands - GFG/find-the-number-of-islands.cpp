//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void dfs(int i, int j, vector<vector<char>> &grid){
        int n=grid.size(),m=grid[0].size();
        
        grid[i][j]='2';
        for(int a=-1;a<2;a++){
            for(int b=-1;b<2;b++){
                int ni=i+a,nj=j+b;
                
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='1')dfs(ni,nj,grid);
                
            }
        }
        
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1')dfs(i,j,grid),islands++;
            }
        }
        return islands;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends