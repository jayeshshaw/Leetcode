
const int MOD =1e9+7;
class Solution {
public:
    
    long  f(int ind,vector<int> &v,unordered_map<int,int> &m,vector<int> &dp){
        
        if(dp[ind]!=-1)return dp[ind];
        
        long  ans=1;
        for(int i=0;i<ind;i++){
            if(v[ind]%v[i]==0 && m.find(v[ind]/v[i])!=m.end()){
                long  a=f(i,v,m,dp);
                long  b=f(m[v[ind]/v[i]],v,m,dp);
                
                ans=(ans+ (a*b))%MOD;
                // cout<<rootval<<"-> "<<v[i]<<","<<rootval/v[i]<<"--"<<a<<" "<<b<<endl;
            }
        }
        return dp[ind]= ans;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        long  ans=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)m[arr[i]]=i;
        // for(auto i: arr)m[i]++;
        
        vector<int> dp(n,-1);
        
        for(int i=0;i<n;i++){
            long k=f(i,arr,m,dp)%MOD;
            ans=(ans+k)%MOD;
            // cout<<" ==="<<k<<endl;
        }
        return ans;
    }
};