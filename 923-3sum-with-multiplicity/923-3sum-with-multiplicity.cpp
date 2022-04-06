class Solution {
public:
    int threeSumMulti(vector<int>& arr, int t) {
        int n=arr.size(),ans=0,mod=1e9+7;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++) {
            ans=(ans+m[t-arr[i]])%mod;
            for(int j=0;j<i;j++)m[arr[i]+arr[j]]++;
        }
        return ans;
    }
};