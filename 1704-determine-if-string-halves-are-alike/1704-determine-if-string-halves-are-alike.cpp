class Solution {
public:
    bool isvowel(char c){
        if( c=='A' || c=='a' ||c=='E' || c=='e' ||c=='I' || c=='i' ||c=='O' || c=='o' ||c=='U' || c=='u')return 1;
        return 0;
    }
    bool halvesAreAlike(string s) {
        int a=0;
        int i,n=s.size();
        for(i=0;i<n/2;i++){
            if(isvowel(s[i]))a++;
        }
        for(;i<n;i++){
            if(isvowel(s[i]))a--;
        }
        return a==0;
    }
};