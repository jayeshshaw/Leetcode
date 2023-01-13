class Solution {

private:
    vector<vector<int>> adj;
    int ans=0;
    int f(int node, vector<int> &parent, string &s){
        if(adj[node].size()==0)return 1;
        
        vector<int> sub;
        
        int hoskta=0;
        int mx=-1,smx=-1;
        for(auto i: adj[node]){
            int k=f(i,parent,s);
            
            if(s[i]==s[node]){hoskta++;continue;}
            if(k>mx){
                smx=mx;mx=k;
            }
            else smx=max(smx,k);
        }
        int n=adj[node].size();
        
        int iska=0;
        if(hoskta<=n-2)iska=mx+smx+1;
        ans=max(ans,iska);
        
        
        int ret=1;
        if(hoskta<n)ret+=mx;
        
        
        // cout<<node<<" "<<"-> "<<iska<<" "<<ret<<endl;
        ans=max(ans,ret);
        return ret;
    }
    

public:
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();
        adj.resize(n);
        ans=0;
        for(int i=1;i<n;i++) adj[parent[i]].push_back(i);
        int k=f(0,parent,s);
        
        return max(ans,k);
    }
};