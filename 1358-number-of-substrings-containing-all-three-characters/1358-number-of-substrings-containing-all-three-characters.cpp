class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> v(3,0);
        int left=0,right=0,n=s.size();
        int ans=0;
        while(right<n){
            v[s[right]-'a']++;
            
            while(v[0] && v[1] && v[2]){
                v[s[left++]-'a']--;
            }
            ans+=left;
            right++;
        }
        return ans;
    }
};