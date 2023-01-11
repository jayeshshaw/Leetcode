class Solution {

private:
    int makevalue(int node,int par, vector<bool> &hasApple, vector<int> &value, vector<vector<int>> &adj){
        int val=hasApple[node];
        
        for(auto i: adj[node]){
            if(i!=par)val+=makevalue(i,node,hasApple,value,adj);
        }
        value[node]=val;
        return val;
    }
    
    int time=0;
    int makeans(int node, int par,  vector<bool> &hasApple, vector<int> &value, vector<vector<int>> &adj){
        if(value[node]==0)return time;
        for(auto i: adj[node]){
            if(i!=par && value[i]!=0){
                time+=2;
                makeans(i,node,hasApple,value,adj);
            }
        }
        return time;
    }
    
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> value(n,0);
        vector<vector<int>> adj(n);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int v=makevalue(0,-1,hasApple,value,adj);
        time =0;
        int t=makeans(0,-1,hasApple,value,adj);
        return time;
    }
};