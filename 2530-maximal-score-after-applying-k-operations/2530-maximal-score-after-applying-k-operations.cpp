class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        multiset<int,greater<int>> m;
        for(auto i: nums)m.insert(i);
        while(k--){
            int k=*m.begin();m.erase(m.begin());
            ans+=k;
            k=ceil((k*1.0)/3);
            m.insert(k);
        }
        return ans;
    }
};