class Solution {
public:
    int maxSubArray(vector<int>& v) {
        long long ans=v[0],n=v.size();
        long long sm=0;
        for(int i=0;i<n;++i){
            sm+=v[i];ans=max(sm,ans);
            sm=max(0ll,sm);
        }
        return ans;
    }
};