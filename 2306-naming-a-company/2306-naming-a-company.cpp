class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char, vector<string>> mp;
        vector<pair<char,vector<string>>> v;
        for(auto i: ideas){
            string s=i.substr(1,i.size()-1);
            mp[i[0]].push_back(s);
        }
        for(auto i: mp)v.push_back({i.first,i.second});
        
        long long ans=0;
        for(int i=0;i<v.size();i++){
            unordered_map<string, int> iska;
            for(auto s: v[i].second)iska[s]=1;
            int a=v[i].second.size();
            for(int j=i+1;j<v.size();j++){
                long long b=v[j].second.size();
                long long common=0;
                for(auto s: v[j].second)if(iska[s]==1)common++;   
                b-=common;
                ans+=2*(b*(a-common));
            }
        }
        return ans;
    }
};