class Solution {
private:
    vector<int> vis;
    vector<vector<int>> adj;
    
    int dfs(int node, int par){
        vis[node]=1;
        int ans=1;
        for(auto i: adj[node]){
            if(i!=par && vis[i]==0){
                ans+=dfs(i,node);
            }
        }
        return ans;
    }
    
    
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vis.assign(n,0);
        adj.resize(n);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        long long rest=n;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int nodes=dfs(i,-1);
                ans+=(rest-nodes)*nodes;
                rest-=nodes;
            }
        }
        return ans;
    }
};