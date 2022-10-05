class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,set<int>> mp;
        for(auto i: logs){
            mp[i[0]].insert(i[1]);
        }
        vector<int> ans(k,0);
        for(auto i: mp){
            int sz=i.second.size();
            ans[sz-1]++;
        }
        return ans;
    }
};