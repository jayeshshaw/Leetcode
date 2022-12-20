class Solution {
public:
    
    void dfs(int i, vector<int> &v, vector<vector<int>> &rooms){
        if(v[i]==0)return;
        v[i]=0;
        for(auto r: rooms[i]){
            dfs(r,v,rooms);
        }
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> v(n,1);
        dfs(0,v,rooms);
        for(auto i: v){
            if(i==1)return 0;
        }
        return 1;
    }
};