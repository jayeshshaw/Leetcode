class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long ans=1;
        int n=nums.size();
        multiset<int> ms;
        for(auto i: nums)ms.insert(i);
        
        while(k>0){
            int top=*ms.begin();top++;
            k--;
            ms.erase(ms.begin());
            ms.insert(top);
        }
        int mod=1000000000+7;
        for(auto i: ms)ans=(ans*i)%mod;
        return ans;
    }
};