class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n=v.size();
        int len=n-k;
        int tot=accumulate(v.begin(),v.end(),0);
        // if(len==1)return tot-*min_element(v.begin(),v.end());
        if(len==0)return tot;
        vector<int> pre(n,0);
        pre[0]=v[0];
        for(int i=1;i<n;i++)pre[i]+=pre[i-1]+v[i];
        
        // for(int i: pre)cout<<i<<" ";
        
        
        int l=0,r=len-1;
        int ans=tot-pre[r];
        // cout<<ans<<endl;
        r++;
        while(r<n){
            int sm=pre[r++]-pre[l++];
            ans=max(ans,tot-sm);
        }
        return ans;
    }
};