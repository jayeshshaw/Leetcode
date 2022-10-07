class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x=0;
        for(auto i: nums)x^=i;
        int last_different_bit=x&(-x);
        int a=0,b=0;
        
        for(auto i: nums){
            if(i&last_different_bit)a^=i;
            else b^=i;
        }
        return {a,b};
    }
};