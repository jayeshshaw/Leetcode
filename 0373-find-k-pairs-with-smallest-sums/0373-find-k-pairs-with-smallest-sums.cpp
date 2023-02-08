class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int a=nums1.size(),b=nums2.size();
        multiset<vector<int>> m;
        m.insert({nums1[0]+nums2[0],0,0});
        while(m.size()>0 && ans.size()<k){
            auto v=*m.begin();m.erase(m.begin());
            int x=v[1],y=v[2];
            ans.push_back({nums1[x],nums2[y]});
            
            if(y==0 && x+1<a)m.insert({nums1[x+1]+nums2[y],x+1,y});
            if(y+1<b)m.insert({nums1[x]+nums2[y+1],x,y+1});
        }
        return ans;
    }
};