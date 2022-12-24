class Solution {
public:
    int mod=1000000007;    
    int numTilings(int n) {
        if(n<=2)return n;
        if(n==3)return 5;
        long long a=1,b=2,c=5;
        for(int i=4;i<=n;i++){
            long long abhi=(2*c)%mod+a;
            a=b,b=c,c=abhi%mod;
        }
        return c;
    }
};