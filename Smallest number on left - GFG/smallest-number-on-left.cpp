//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        stack<vector<int>> st;
        vector<int> nextSmallerArray(n,-1);
        for(int i=n-1;i>=0;i--){
            if(st.size()==0){st.push({arr[i],i});continue;}
            
            while(st.size()>0 && arr[i]<st.top()[0]) {
                vector<int> top=st.top();st.pop();
                nextSmallerArray[top[1]]=arr[i];
            }       
            st.push({arr[i],i});
        }
        return nextSmallerArray;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends