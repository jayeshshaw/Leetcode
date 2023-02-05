class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())return {};
        vector<int> indexes;
        vector<int> hash_of_p(26,0),hash_of_window(26,0);
        for(char c: p)hash_of_p[c-'a']++;
        
        int n=p.size();
        for(int i=0;i<n;i++)hash_of_window[s[i]-'a']++;
        
        if(hash_of_p==hash_of_window)indexes.push_back(0);
        for(int i=n;i<s.size();i++){
            hash_of_window[s[i]-'a']++;
            hash_of_window[s[i-n]-'a']--;
            if(hash_of_p==hash_of_window)indexes.push_back(i-n+1);
        }
        return indexes;
    }
};