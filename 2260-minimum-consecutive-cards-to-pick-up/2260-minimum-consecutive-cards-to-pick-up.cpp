class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<cards.size();i++){
            m[cards[i]].push_back(i);
        }
        int ans=cards.size();
        bool present=false;
        for(auto e: m){
            if(e.second.size()>1)present =true;
            for(int i=1;i<e.second.size();i++){
                cout<<ans<<" ";
                ans=min(ans,e.second[i]-e.second[i-1]+1);
            }            
        }
        if(present)return ans;
        return -1;
    }
};