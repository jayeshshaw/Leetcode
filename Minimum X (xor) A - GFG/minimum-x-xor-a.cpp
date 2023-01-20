//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int aa=__builtin_popcount(a);
        int bb=__builtin_popcount(b);
        if(aa==bb)return a;
        int ans=0;
        int i=0;
        
        if(aa<bb){
            ans=0;
            bb-=aa;
            while(bb>0){
                if(((a>>i)&1)==0)ans+=1<<i,bb--;
                i++;
            }
            return ans+a;
        }
        else if(aa>bb){
            i=31;ans=0;
            while(bb>0){
                if(((a>>i)&1)==1)ans+=(1<<i),bb--;
                i--;
            }
            return ans;
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends