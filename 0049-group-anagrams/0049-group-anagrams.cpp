class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s ) {
        unordered_map<string,vector<string>> m;
        for(auto i: s){
            string p=i;
            sort(begin(p),end(p));
            m[p].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto i: m){
            vector<string> temp;
            for(auto s: i.second)temp.push_back(s);
            ans.push_back(temp);
        }
        return ans;
    }
};