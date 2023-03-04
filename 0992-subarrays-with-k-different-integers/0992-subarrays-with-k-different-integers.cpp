class Solution {
    int atmost(vector<int> &v, int k){
        int start=0,end=0;
        int ans=0,n=v.size();
        unordered_map<int,int> mp;
        int ele=0;
        while(end<n){
            if(mp[v[end]]==0){ele++;}
            mp[v[end]]++;
            while(ele>k){
                mp[v[start]]--;
                if(mp[v[start]]==0)ele--;
                start++;
            }
            ans+=end-start+1;
            end++;
        }
        return ans;
    }
    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1) ;       
    }
};