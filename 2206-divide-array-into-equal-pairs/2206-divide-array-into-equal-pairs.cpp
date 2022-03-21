class Solution {
public:
    bool divideArray(vector<int>& nums) {
            vector<int> v(500,0);
        for(auto i:nums){v[i-1]++;}
        for(auto i: v){if(i%2!=0)return 0;}
        return 1;
    }
};