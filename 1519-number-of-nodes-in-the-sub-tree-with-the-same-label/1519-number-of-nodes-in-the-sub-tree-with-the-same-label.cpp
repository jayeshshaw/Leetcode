class Solution {
private:
    vector<int> ans;
    vector<vector<int>> adj;
    string lables;
    
    vector<int> dfs(int node,int par){
        vector<int> v(26,0);
        int c=(lables[node]-'a');
        v[c]++;
        for(auto i: adj[node]){
            if(i!=par){
                vector<int> vv=dfs(i,node);
                for(int j=0;j<=25;j++)v[j]+=vv[j];
            }
        }
        ans[node]=v[c];
        return v;
    }
    
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string s) {
        ans.resize(n,0);
        adj.resize(n);
        lables=s;
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0,-1);
        return ans;
        
    }
};