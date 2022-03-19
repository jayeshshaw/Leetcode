class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string s=to_string(k);
        int i=s.size()-1;
        int j=num.size()-1;
        int c=0;
        while(i>=0 || j>=0 || c>0){
            if(j>=0)c+=num[j];
            if(i>=0)c+=s[i]-'0';
            
            if(j>=0) num[j]=c%10;
            else num.insert(num.begin(),c%10);
            c=c/10;
            
            i--;j--;
        }
        return num;        
    }
};