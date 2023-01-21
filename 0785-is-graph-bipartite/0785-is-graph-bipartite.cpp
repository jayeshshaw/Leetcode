class Solution {
private:
	vector<int> col;
    bool dfs(int node,int par, vector<vector<int>>adj){
        bool ans=true;
        for(auto i: adj[node]){
            if(col[i]==-1){
                col[i]=1-col[node];
                if(i!=par)
                if(!dfs(i,node,adj))ans= false;
            }
            else if(col[i]==col[node])ans= false;
        }
        // if(ans)cout<<node<<" ";
        return ans;
    }
    
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int v=adj.size();
	    col.resize(v,-1);
	    for(int i=0;i<v;i++)col[i]=-1;
	    
	    int ans=true;
        for(int i=0;i<v;i++){
            // cout<<i<<" ";
            if(col[i]==-1)col[i]=0,ans &=dfs(i,-1,adj);
            // cout<<col[i]<<endl;
        }
        return ans;
    }
};