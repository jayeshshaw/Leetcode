//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // int beautySum(string s) {
    //     long long ans=0;
    //     for(int i=0;i<s.size();i++){
    //         unordered_map<char,int> mp;
    //         int mx=-1e9,mn=1e9;
    //         for(int j=i;j<s.size();j++){
    //             mp[s[j]]++;
    //             mn=min(mn,mp[s[j]]);
    //             mx=max(mx,mp[s[j]]);
    //             cout<<mx-mn;
    //             ans+=mx-mn;
    //         }
    //     }
    //     return ans;
    // }
    int beautySum(string s) {
        int ans = 0;
        for (auto i = 0; i < s.size(); ++i) {
            int cnt[26] = {}, max_f = 0, min_f = 0;
            for (auto j = i; j < s.size(); ++j) {
                int idx = s[j] - 'a';
                max_f = max(max_f, ++cnt[idx]);
                if (min_f >= cnt[idx] - 1) {
                    min_f = cnt[idx];
                    for (int k = 0; k < 26; ++k)
                        min_f = min(min_f, cnt[k] == 0 ? INT_MAX : cnt[k]);
                }
                ans += max_f - min_f;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends