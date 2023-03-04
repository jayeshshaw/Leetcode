class Solution {
private:
    int atmost(vector<int> &v, int k){
        int start=0,end=0;
        int n=v.size();
        int count=0,ans=0;
        while(start<n && end<n){
            count+=v[end]%2;
            while(count>k){
                count-=(v[start++]%2);
            }
            ans+=end-start+1;
            end++;
        }
        return ans;
    }
    
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};