class Solution {
public:
    unordered_map<char,int> hash(string s){
        unordered_map<char,int> mp;
        for(auto i: s)mp[i]++;
        return mp;
    }
    bool isAnagram(string s, string t) {
        return hash(s)==hash(t);
    }
};