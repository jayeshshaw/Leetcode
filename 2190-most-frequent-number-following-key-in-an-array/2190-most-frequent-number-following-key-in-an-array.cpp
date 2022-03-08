class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> m;
        int mx=INT_MIN,ans=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==key){
                m[nums[i+1]]++;
                if(m[nums[i+1]]>mx){
                    mx=m[nums[i+1]];
                    ans=nums[i+1];
                }
            }
        }
        return ans;
    }
};