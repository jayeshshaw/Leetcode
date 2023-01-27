class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& v, int k) {
        multiset<pair<int,int>> m;
        for(int i=0;i<v.size();i++){
            m.insert({v[i][k],i});
        }
        vector<vector<int>> ans(v.size());
        int i=0;
        while(m.size()>0){
            auto p=*m.begin();
            ans[i++]=v[p.second];
            m.erase(m.begin());
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};