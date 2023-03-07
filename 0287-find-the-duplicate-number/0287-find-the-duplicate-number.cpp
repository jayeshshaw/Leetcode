class Solution {
public:
    int findDuplicate(vector<int>& v) {
        sort(begin(v),end(v));
        int l=0,h=v.size();
        int ans;
        while(l<h){
            int m=l+(h-l)/2;
            // cout<<l<<" "<<h<<" "<<m<<endl;
            if(v[m]<m+1)h=m;
            else l=m+1;
        }
        return h;
    }
};