class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans=0;
        vector<pair<int,int>> v;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            v.push_back({nums1[i],nums2[i]});
        }
        sort(rbegin(v),rend(v));
        multiset<pair<int,int>> m;
        long long sm=0,ele=0;
        for(int i=0;i<n;i++){
            sm+=v[i].first;
            ele++;
            m.insert({v[i].second,v[i].first});
            if(ele==k){
                auto p=*m.begin();
                m.erase(m.begin());
                
                long long abhi=p.first*sm;
                ans=max(ans,abhi);
                sm-=p.second;
                ele--;
            }
        }
        return ans;
    }
};