class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> c(5,1);
        for(int i=1;i<n;i++){
            for(int j=3;j>=0;j--)c[j]+=c[j+1];
            
        }
        return accumulate(c.begin(),c.end(),0);
    }
};