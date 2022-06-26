class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int n=v.size();
        
        vector<int> dp(n,1),hash(n),lis;
        sort(v.begin(),v.end());
        int mx=1;
        int last=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(v[i]%v[prev]==0 && 1+dp[prev]>dp[i])
                    dp[i]=max(dp[i],1+dp[prev]),
                    hash[i]=prev;
            }
            if(dp[i]>mx){
                mx=dp[i];
                last=i;
            }
        }
        lis.resize(mx);
        lis[0]=v[last];
        int ind=1;
        while(hash[last]!=last){
            last=hash[last];
            lis[ind++]=v[last];
        }
        reverse(lis.begin(),lis.end());
        return lis;
    }
};