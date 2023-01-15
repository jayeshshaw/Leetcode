class Solution {
private:
    vector<int> p;
    vector<int> node;
    vector<vector<int>> adj;

    void make(int v){p[v]=v;node[v]=1;}

    int find(int x){return (x==p[x]?x:(p[x]=find(p[x])));}

    bool join(int a, int b){
      a=find(a);b=find(b); 
      if(a==b)return 0; 
      if(node[a]<node[b])swap(a,b); 
      p[a]=b;
      node[b]+=node[a];
      return 1;
    }
    

public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        p.resize(n,-1);
        node.resize(n,0);
        
        adj.resize(n);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++)mp[vals[i]].push_back(i);
        
        for(int i=0;i<n;i++)make(i);
        
        int ans=0;
        for(auto i: mp){
            for(auto ind:i.second)
                for(auto nei:adj[ind]){
                    if(vals[nei]<=vals[ind])join(nei,ind);
                }
            unordered_map<int,int> count;
            for(auto ind: i.second){
                int k=find(ind);
                count[k]++;
                ans+=count[k];
            }
        }
        return ans;
    }
};