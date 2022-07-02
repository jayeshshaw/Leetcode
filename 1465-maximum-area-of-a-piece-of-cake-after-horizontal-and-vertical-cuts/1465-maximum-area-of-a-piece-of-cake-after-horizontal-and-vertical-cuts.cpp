class Solution {
public:
    int maxArea(int h, int w, vector<int>& hr, vector<int>& vr) {
        long long mod=1e9+7;
        hr.push_back((h%mod)%mod);
        vr.push_back((w%mod)%mod);
        sort(hr.begin(),hr.end());
        sort(vr.begin(),vr.end());
        
        int x=hr[0],y=vr[0];
        for(int i=1;i<hr.size();i++)
            x=max(x,hr[i]-hr[i-1]);
        for(int i=1;i<vr.size();i++)
            y=max(y,vr[i]-vr[i-1]);
        
        
        long long ans=x%mod*y%mod;
        
        return ans%mod;
    }
};