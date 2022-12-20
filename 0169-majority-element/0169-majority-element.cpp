class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=0,count=0;
        for(auto i: nums){
            if(count==0)element=i;
            if(i==element)count++;
            else count--;
        }
        return element;
    }
};