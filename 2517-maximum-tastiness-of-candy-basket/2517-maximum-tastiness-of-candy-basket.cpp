class Solution {
public:
       
bool f(int k, int n, vector<int> &v, int ans){
    int abhi=v[0];
    int ff=1;
    for(int i=1;i<n;i++){
        if(v[i]-abhi>=ans){
            ff++;
            abhi=v[i];
        }
        if(ff==k)return true;
    }
    return 0;
}
    int maximumTastiness(vector<int>& v, int k) {
        sort(begin(v),end(v));
        int n=v.size();
        
        int l=0,h=v[n-1]-v[0];
        while(l<=h){
            int mid=l+(h-l)/2;
            if(f(k,n,v,mid))l=mid+1;
            else h=mid-1;
        }
        return h;
    }
};