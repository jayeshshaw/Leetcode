//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {// Create an empty Hash to store mapping from sum to 
        // pair indexes 
        map<int, pair<int, int> > Hash;
        vector<int> Ans;
        
        int flag = 0;
    
        for(int i=0; i<N; ++i)
        {
            for(int j=i+1; j<N; ++j)
            {
                // If sum of current pair is not in hash, 
                // then store it and continue to next pair 
                int sum = A[i] + A[j];
                
                if (Hash.find(sum) == Hash.end())
                {
                    Hash[sum] = make_pair(i, j); 
                    continue;
                }

                // Find previous pair 
                pair<int, int> pp = Hash[sum];// pp->previous pair

                if(pp.first != i && pp.first != j && pp.second != i && pp.second != j)
                {
                    vector<int> ans(4);

                    ans[0] = pp.first;
                    ans[1] = pp.second;
                    ans[2] = i;
                    ans[3] = j;

                    if (Ans.size() == 0)
                        Ans = ans;

                    // Checking whether the current pairs are lexiographically smallest
                    else
                    {
                        bool shouldReplace = false;
                        for (int i1 = 0; i1 < Ans.size(); i1++)
                        {
                            if (Ans[i1] < ans[i1])
                                break;
                            if (Ans[i1] > ans[i1])
                            {
                                shouldReplace = true;
                                break;
                            }
                        }
                        // We replace the pairs if we find a lexiographically smaller pair
                        if (shouldReplace)
                            Ans = ans;
                    }
                }
            }
        }

        if(Ans.size() == 0)
        {
            vector<int> a(4,-1);
            return a;
        }
        
        return Ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends