class Solution {
public:
    int minPartitions(string n) {
        char ans='0';
        for(auto i: n){
            if(i>ans)ans=i;
        }
        return ans-'0';
    }
};