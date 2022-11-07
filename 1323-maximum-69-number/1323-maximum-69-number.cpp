class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int n=s.size();
        int i=0;
        while(i<n){
            if(s[i]=='6')break;
            i++;
        }
        if(i<n)s[i]='9';
        num=stoi(s);
        return num;
    }
};