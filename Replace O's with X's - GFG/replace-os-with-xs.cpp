//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    
private:
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,1,0,-1};
    void dfs(int i, int j, vector<vector<char>> &m, vector<vector<int>> &vis){
        vis[i][j]=1;
        int n=m.size();
        int mm=m[0].size();
        for(int x=0;x<4;x++){
            int ni=i+drow[x];
            int nj=j+dcol[x];
            if(ni>=0 && ni<n && nj>=0 && nj<mm && vis[ni][nj]==0 &&  m[ni][nj]=='O')dfs(ni,nj,m,vis);
        }
    }
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0]&& mat[i][0]=='O')dfs(i,0,mat,vis);
            if(!vis[i][m-1]&& mat[i][m-1]=='O')dfs(i,m-1,mat,vis);
        }
        
        for(int i=0;i<m;i++){
            if(!vis[0][i]&& mat[0][i]=='O')dfs(0,i,mat,vis);
            if(!vis[n-1][i]&& mat[n-1][i]=='O')dfs(n-1,i,mat,vis);
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<vis[i][j]<<" ";
                if(vis[i][j]==0 && mat[i][j]=='O')mat[i][j]='X';
            }
            // cout<<endl;
        }
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends