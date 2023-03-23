class Solution {
private:
    vector<int> vis;
    vector<vector<int>> adj;
    void dfs(int node, int par){
        vis[node]=1;
        for(auto i: adj[node]){
            if(!vis[i] && i!=par)dfs(i,node);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        vis.assign(n,0);
        adj.resize(n);
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i])ans++,dfs(i,-1);
        }
        return ans-1;
    }
};