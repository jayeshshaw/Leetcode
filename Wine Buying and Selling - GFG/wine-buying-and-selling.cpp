//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& v, int n){
      long long ans=0;
      queue<vector<int>> q;
      for(int i=0;i<n;i++){
          if(q.size()==0){q.push({v[i],i});continue;}
          
          auto p=q.front();
          if((p[0]<0 && v[i]<0) || (p[0]>0 && v[i]>0)){q.push({v[i],i});continue;}
          
          
            //   cout<<i<<"-> ";
          while(v[i]!=0 && q.size()>0){
              auto p=q.front();
              if(abs(p[0])<=abs(v[i])){
                  v[i]+=p[0];
                  ans+=abs(p[0])*abs(i-p[1]);;
                  q.pop();
              }
              else{
                  ans+=abs(v[i])*abs(i-p[1]);
                  q.front()[0]+=(v[i]);
                  v[i]=0;
              }
          }
          if(v[i]!=0)q.push({v[i],i});
        //       if(q.size()>0)
        //       cout<<q.front()[0]<<" "<<q.front()[1]<<" ";
        //   cout<<ans<<endl;
      }
    //   while(q.size()>0){
    //       auto p=q.front();q.pop();
    //       cout<<p[0]<<" "<<p[1]<<endl;
    //   }
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends