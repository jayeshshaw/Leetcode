//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
        
private:
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,1,0,-1};
    void dfs(int i, int j, vector<vector<int>> &m, vector<vector<int>> &vis){
        vis[i][j]=1;
        int n=m.size();
        int mm=m[0].size();
        for(int x=0;x<4;x++){
            int ni=i+drow[x];
            int nj=j+dcol[x];
            if(ni>=0 && ni<n && nj>=0 && nj<mm && vis[ni][nj]==0 &&  m[ni][nj]==1)dfs(ni,nj,m,vis);
        }
    }
    
  public:
    int numberOfEnclaves(vector<vector<int>> &mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0]&& mat[i][0]==1)dfs(i,0,mat,vis);
            if(!vis[i][m-1]&& mat[i][m-1]==1)dfs(i,m-1,mat,vis);
        }
        
        for(int i=0;i<m;i++){
            if(!vis[0][i]&& mat[0][i]==1)dfs(0,i,mat,vis);
            if(!vis[n-1][i]&& mat[n-1][i]==1)dfs(n-1,i,mat,vis);
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<vis[i][j]<<" ";
                if(vis[i][j]==0 && mat[i][j]==1)ans++;
            }
            // cout<<endl;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends