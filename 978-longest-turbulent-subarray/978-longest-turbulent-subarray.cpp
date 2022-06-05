class Solution {
public:
    int maxTurbulenceSize(vector<int>& v) {
        int ans=0;
        int c=0,i;
        for(i=0;i<v.size()-1;++i){
            if(v[i]>v[i+1])c=max(1,c+1);
            else if(v[i]<v[i+1])c=min(-1,c-1);
            else c=0;
            ans=max(ans,abs(c));
            c*=-1;
        }
        return ans+1;
    }
};