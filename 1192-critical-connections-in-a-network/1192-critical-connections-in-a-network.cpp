class Solution {
public:
    vector<vector<int>> ans,g;
    vector<int> in;
    vector<int> low;
    vector<bool> vis;
    int time=0;
    
    void dfs(int node,int parent){
        in[node]=time;
        low[node]=time++;
        vis[node]=true;
        for(int &x: g[node]){
            if(!vis[x] && parent!=x){
                dfs(x,node);
                low[node]=min(low[node],low[x]);
                if(in[node]<low[x])
                    ans.push_back({x,node});
                continue;
            }
            else if(parent!=x) low[node]=min(low[node],in[x]);            
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        g.resize(n);in.resize(n,0);low.resize(n,0);
        vis.resize(n,false);
        time=0;
        for(auto i: conn){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i,i);
        }
        return ans;
    }
};