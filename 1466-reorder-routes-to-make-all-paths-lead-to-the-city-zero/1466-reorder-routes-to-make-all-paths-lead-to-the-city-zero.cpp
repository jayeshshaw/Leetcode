class Solution {
private:
    unordered_map<int,vector<int>> mp;
    vector<vector<int>> adj;
    
    int dfs(int node, int par){
        int ans=0;
        for(auto i: adj[node]){
            if(i!=par){
                ans++;
                for(auto ind: mp[i]){
                    if(ind==node){ans--;break;}
                }
                ans+=dfs(i,node);
            }
        }
        return ans;
    }
    
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            mp[i[0]].push_back(i[1]);
        }
        
        return dfs(0,-1);
        
    }
};