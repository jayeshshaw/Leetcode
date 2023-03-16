//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int s, int d){
        // code here 
        if(9*d<=s)return "-1";
        
        string ans="1";
        for(int i=1;i<d;i++)ans.push_back('0');
        s-=1;
        // cout<<ans<<" ";
        for(int i=d-1;s>0 && i>=0;i--){
            int poss=min(s,9-(ans[i]-'0'));
            ans[i]+=poss;
            s-=poss;
        }
        // cout<<ans<<" ";
        for(int i=d-1;i>0;i--){
            if(ans[i-1]<'9'){
                ans[i]=ans[i]-1;
                ans[i-1]=ans[i-1]+1;
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends