class Solution {
public:
    int minSetSize(vector<int>& arr) {
        multiset<int ,greater<int>> m;
        unordered_map<int,int> mp;
        for(auto i: arr)mp[i]++;
        for(auto i: mp)m.insert(i.second);
        int n=arr.size();
        int ans=0;
        int removed=0;
        while(removed<n/2){
            ans++;
            removed+=*m.begin();
            m.erase(m.begin());
        }
        return ans;
    }
};