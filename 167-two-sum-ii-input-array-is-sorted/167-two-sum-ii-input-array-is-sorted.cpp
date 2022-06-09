class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int a=0,b=v.size()-1;
        while(a<b){
            if(v[a]+v[b]==target)break;
            else if(v[a]+v[b]>target)b--;
            else a++;
        }
        return {a+1,b+1};
    }
};