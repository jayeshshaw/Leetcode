class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto i: s)mp[i]++;
        vector<pair<int,char>> p;
        for(auto i: mp){
            p.push_back({i.second,i.first});
        }
        sort(rbegin(p),rend(p));
        s.clear();
        for(auto i: p){
            while(i.first--)s+=i.second;
        }
        return s;
    }
};