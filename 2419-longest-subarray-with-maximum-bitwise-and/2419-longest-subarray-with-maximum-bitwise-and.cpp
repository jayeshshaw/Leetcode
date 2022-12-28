class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int mx=0;
        for(auto i: v)mx=max(i,mx);
        
        int ans=1;
        int n=v.size();
        for(int i=0;i<n;){
            if(v[i]!=mx){i++;continue;}
            int eles=0;
            int val=v[i];
            while(i<n && val==v[i]){eles++;i++;}
            ans=max(ans,eles);
        }
        return ans;
    }
};