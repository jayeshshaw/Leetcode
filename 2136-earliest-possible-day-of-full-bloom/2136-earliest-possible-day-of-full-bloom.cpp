class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        int n=p.size();
        
        vector<vector<int>> pg;
        for(int i=0;i<n;i++){
            pg.push_back({g[i],p[i]});
        }
        sort(begin(pg),end(pg));
        
        int ans=0,mn=1e9;
        // for(auto i: g)ans=max(ans,i),mn=min(i,mn);
        
        // int extra=ans-mn;
        
        for(int i=0;i<n;i++){
            int tobe=pg[i][1];
            int already=max(ans,pg[i][0]);
            
            ans=already+tobe;
        }
        return ans;
    }
};