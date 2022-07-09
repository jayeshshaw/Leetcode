class Solution {
public:
    
    void dfs(int i, vector<vector<int>> &g, vector<bool> &vis){
        vis[i]=1;
        for(auto adj: g[i]){
            if(vis[adj]==0)
                dfs(adj,g,vis);
        }
    }
    
    
    
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>> g(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && v[i][j]==1)g[i].push_back(j);
            }
        }
        vector<bool> vis(n,0);
        int comp=0;
        for(int i=0;i<n;i++){
            // cout<<i<<" "<<vis[i]<<endl;
            if(!vis[i]){
                comp++;
                // vis[i]=1;
                dfs(i,g,vis);
            }
            
        }
        return comp;
    }
};