//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    private:
    int hopes=1;
    bool hoskta(string s){
        int n=s.size();
        string p=s.substr(0,n/2);
        string q=s.substr(n/2,n/2);
        return p==q;
    }
    
  public:
    int minOperation(string s) {
        if(s.size()==1)return 1;
        // cout<<s<<endl;
        
        if(s.size()%2!=0 || !hoskta(s) || hopes<=0){
            return 1+minOperation(s.substr(0,s.size()-1));
        }
        hopes--;
        return 1+minOperation(s.substr(0,s.size()/2));

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends