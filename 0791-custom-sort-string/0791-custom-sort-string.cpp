class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(auto i: s)mp[i]++;
        string ans="";
        for(auto i: order){
            while(mp[i]>0)ans+=i,mp[i]--;
        }
        for(auto i: s){
            if(mp[i]>0)ans+=i,mp[i]--;
        }
        return ans;
    }
};