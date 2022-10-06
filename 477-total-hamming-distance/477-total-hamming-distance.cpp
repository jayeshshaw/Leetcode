class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        vector<int> v(32,0);
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            for(int j=0;j<32;j++){
                if(n&(1<<j))v[j]++;
            }
        }
        int n=nums.size();
        for(auto i: v){
            int set=i;
            ans+=i*(n-i);
        }
       
        return ans;
    }
};