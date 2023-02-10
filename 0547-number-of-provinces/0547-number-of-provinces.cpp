class Solution {
private:
    vector<int> vis;
    vector<vector<int>> adj;
    void dfs(int node){
        vis[node]=1;
        for(auto i: adj[node]){
            if(!vis[i])dfs(i);
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& vv) {
        int n=vv.size();
        adj.resize(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vv[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vis.resize(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
};