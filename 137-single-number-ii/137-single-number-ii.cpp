class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> v(32,0);
        for(int i: nums){
            int bit=0;
            while(bit<32){
                if(i&(1<<bit))v[bit]++;
                bit++;
            }
        }
        int ans=0,bit=0;
        for(auto i: v){
            if(i%3)ans+=1<<bit;
            bit++;
        }
        return ans;
    }
};