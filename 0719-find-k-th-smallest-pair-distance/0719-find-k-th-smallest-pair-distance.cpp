class Solution {
private:
    int kitnapair(vector<int> &nums, int m){
        int ans=0;
        for(int i=0,j=0;i<nums.size();i++){
            while(j<nums.size() && nums[j]-nums[i]<=m)j++;
            ans+=j-i-1;
        }
        return ans;
    }
    
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int l=0,h=1000000;
        while(l<h){
            int m=(l+h)/2;
            int p=kitnapair(nums,m);
            if(p>=k)h=m;
            else l=m+1;
        }
        return l;
    }
};