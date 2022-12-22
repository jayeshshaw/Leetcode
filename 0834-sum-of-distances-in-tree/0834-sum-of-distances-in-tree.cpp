class Solution {
public:
    vector<vector<int>> adj;
    vector<int> childs;
    vector<int> ans;
    
    void makechilds(int node, int par=-1){
        for(auto i: adj[node]){
            if(i==par)continue;
            makechilds(i,node);
            childs[node]+=childs[i];
            ans[0]+=childs[i];
        }
    }
    
    void makeans(int node, int par=-1){
        for(auto i: adj[node]){
            if(i==par)continue;
            ans[i]=ans[node]-2*childs[i]+ans.size();
            makeans(i,node);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj=vector<vector<int>> (n);
        childs.resize(n,1);
        ans.resize(n,0);
        for(auto i: edges){
            int a=i[0],b=i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        makechilds(0);
        makeans(0);
        return ans;
    }
};