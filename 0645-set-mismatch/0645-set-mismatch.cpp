class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i: nums)mp[i]++;
        int a,b;
        int n=nums.size();
        for(int i=1;i<=n;i++){
            if(mp[i]==2)a=i;
            if(mp[i]==0)b=i;
        }
        return {a,b};
    }
};