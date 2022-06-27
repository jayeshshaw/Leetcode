class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        next_permutation(s.begin(),s.end());
        // cout<<s;
        long long k=stoll(s);
        if(k<=n || k>INT_MAX)return -1;
        return k;
    }
};