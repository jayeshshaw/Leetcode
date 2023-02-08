class Solution {
public:
    string frequencySort(string s) {
        set<pair<int,char>, greater<pair<int,char>>> st;
        unordered_map<char,int> mp;
        for(auto i: s)mp[i]++;
        for(auto i: mp)st.insert({i.second,i.first});
        
        string ans;
        while(st.size()>0){
            pair<int,char> p=*st.begin();st.erase(st.begin());
            int a=p.first;
            while(a--)ans+=p.second;
        }
        return ans;
    }
};