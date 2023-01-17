class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int> pref(n,0),suf(n,0);
        pref[0]=s[0]-'0';
        suf[n-1]=(s[n-1]-'0')^1;
        
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1];
            pref[i]+=s[i]-'0';
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1];
            suf[i]+=(s[i]-'0')^1;
        }
        
//         for(auto i: pref)cout<<i<<" ";
//         cout<<endl;
//         for(auto i: suf)cout<<i<<" ";
//         cout<<endl;
        
        int ones=pref[n-1];
        int ans=min(ones,n-ones);
        
        for(int i=1;i<n;i++){
            int picheones=pref[i-1];
            int aagezeros=suf[i];
            // cout<<picheones<<" "<<aagezeros<<"- > ";
            int op=(picheones+aagezeros);
            // cout<<i<<" "<<op<<endl;
            ans=min(ans,op);
        }
        return ans;
        
    }
};