class Solution {
public:
    int n=0;
    int brokenCalc(int s, int t) {
        int ans=0;
        while(s<t){
            ans++;
            if(t&1==1)t++;
            else t/=2;
        }
        ans+=s-t;
        return ans;
    }
    
};