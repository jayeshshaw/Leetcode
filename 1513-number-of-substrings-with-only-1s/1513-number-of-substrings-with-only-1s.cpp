class Solution {
public:
    int numSub(string s) {
        int ans=0;
        int c=0,mod=1e9+7;
        for(auto i: s){
            if(i=='1')c++;
            else c=0;
            ans=(ans+c)%mod;
        }
        return ans;
    }
};