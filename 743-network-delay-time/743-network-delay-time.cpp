class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> v,vector<int> &vis,int &ans,int k){
        if(v[k].size()==0)return;
        
        vector<int> mxi;
        for(auto i: v[k]){
           if(vis[i.first]==0){
               mxi.push_back(i.second);
                vis[i.first]++;
             dfs(v,vis,ans,i.first);
           }
        }
       if(mxi.size()>0) ans+=*max_element(mxi.begin(),mxi.end());
        return;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        for(auto i: times){
            g[i[0]].push_back({i[1],i[2]});
        }
        const int inf = 1e9;
        vector<int> dist(n + 1, inf);
		vector<bool> vis(n + 1, false);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.emplace(0, k);
        int u, v, w;
        while (!pq.empty()) {
            u = pq.top().second; pq.pop();
			if (vis[u]) continue;
			vis[u] = true;
            for (auto& to : g[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == inf ? -1 : ans;
        
    }
    
    int bfs(vector<vector<pair<int,int>>> v,vector<int> &vis,int k){
        queue<int> q;
        int ans=0;
        q.push(k);
        while(!q.empty()){
            int f=q.front();
            q.pop();
            int mx=INT_MIN;
            for(auto i: v[f]){
                if(vis[i.first]==0){
                    q.push(i.first);
                    mx=max(mx,i.second);
                    vis[i.first]++;
                }
            }
            if(mx!=INT_MIN)ans+=mx;
        }
        return ans;
    }
};