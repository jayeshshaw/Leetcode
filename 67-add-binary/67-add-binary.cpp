class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.size()-1,j=b.size()-1;
        int c=0;
        
        while(i>=0 || j>=0 || c>0){
            if(i>=0)c+=a[i]-'0';
            if(j>=0)c+=b[j]-'0';
            ans+=(c%2)+'0';c/=2;
            i--;j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};