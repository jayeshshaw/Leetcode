//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
         int top=0;
        int bottom = matrix.size();
        int left=0;
        int right = matrix[0].size();
        vector<int> vec;
        int i;
        while(top<bottom && left<right)
        {
            for(i=left; i<right; i++)
            {
                vec.push_back(matrix[top][i]);
                // cout<<matrix[top][i]
            }
            top++;
            
            for(i=top; i<bottom; i++)
            {
                vec.push_back(matrix[i][right-1]);
            }
            right--;
            
            
            if(left>=right || top>=bottom) break;
            
            
            for(i=right-1; i>=left; i--)
            {
                vec.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            
            for(i=bottom-1; i>=top; i--)
            {
                vec.push_back(matrix[i][left]);
            }
            left++;
        }
        return vec;
    }
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        vector<int> v=spiralOrder(a);
        reverse(begin(v),end(v));
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends