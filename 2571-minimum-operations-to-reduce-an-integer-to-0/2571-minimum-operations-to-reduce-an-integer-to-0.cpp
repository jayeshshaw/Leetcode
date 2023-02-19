class Solution {
private:
    string decToBinary(int n){
        string ans;
        int i = 0;
        while (n > 0) {
            string p=to_string(n%2);
            ans+=p;
            n = n / 2;
        }
        return ans;
    }
    
public:
    int minOperations(int n) {
        string s=decToBinary(n);
        int ans=0;
        while(n>0){
            if((n&3)==3){
                ans++;
                n++;
            }
            else {
                ans+=n&1;
                n=n>>1;
            }
        }
        return ans;
    }
};