class Solution {
public:
    long long bits(long long n){
        for(long long i=0;i<=31;i++){
            if(pow(2,i)>=n)return i;
        }
        return 0;
    }
    
    int concatenatedBinary(int n) {
        long ans = 0, mod = 1e9+7;
        for (int i = 1; i <= n; ++i) {
            int len = 0;
            for (int j = i; j; j >>= 1, ++len);
            ans = ((ans << len) % mod + i) % mod;
        }
        return ans;
    }
    
};