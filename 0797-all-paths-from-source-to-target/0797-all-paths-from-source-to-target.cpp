class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int node, int par, vector<vector<int>>& graph, vector<int> path){
        
        if(node==graph.size()-1){
            path.push_back(graph.size()-1);
            ans.push_back(path);return;
        }
        
        for(auto i: graph[node]){
            if(i!=par)
                {path.push_back(node);
                dfs(i,node,graph,path);
                path.pop_back();}
        }       
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // vector<int> vis
        dfs(0,-1,graph,{});
        return ans;
    }
};