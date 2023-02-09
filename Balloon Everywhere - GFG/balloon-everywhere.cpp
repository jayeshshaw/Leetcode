//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        string t="balloon";
        unordered_map<char,int> mp1,mp2;
        for(auto i: s)mp1[i]++;
        for(auto i: t)mp2[i]++;
        int ans=INT_MAX;
        for(auto i: t){
            ans=min(ans,mp1[i]/mp2[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends