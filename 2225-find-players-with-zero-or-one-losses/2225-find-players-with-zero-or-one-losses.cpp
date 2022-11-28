class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        for(auto i: matches){
            mp[i[1]]++;
            mp[i[0]]++;mp[i[0]]--;
        }
        vector<vector<int>> ans(2);
        for(auto i: mp){
            if(i.second==0)ans[0].push_back(i.first);
            if(i.second==1)ans[1].push_back(i.first);
        }
        return ans;
    }
};