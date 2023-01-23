class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int n=v.size();
        for(int i=0;i<n;i++){
            while(v[i]>0 && v[i]<=n && v[i]!=v[v[i]-1]){
                swap(v[i],v[v[i]-1]);
            }
        }
        // for(auto i: v)cout<<i<<" ";
        int ans=n+1;
        for(int i=0;i<n;i++){
            if(i+1!=v[i]){ans=i+1;break;}
        }
        return ans;
    }
};