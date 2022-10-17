class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> v(26,0);
        for(auto i: s)v[i-'a']++;
        for(auto i: v)if(i==0)return i;
        return 1;
    }
};