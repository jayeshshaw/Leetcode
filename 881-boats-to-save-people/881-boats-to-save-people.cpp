class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int a=0,b=p.size()-1;
        sort(p.begin(),p.end());
        int ans=0;
        while(a<=b){
            if(p[a]+p[b]<=limit){ans++;a++;b--;}
            else {ans++;b--;}
        }
        return ans;
    }
};