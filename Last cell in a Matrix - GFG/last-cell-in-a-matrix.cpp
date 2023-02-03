//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void move(int &a, int &b, int d){
        if(d==0)b++;
        else if(d==1)a++;
        else if(d==2)b--;
        else a--;
        return;
    }
    
    pair<int,int> endPoints(vector<vector<int>> mat, int R, int C){
        int a=0,b=0;
        int d=0;
        pair<int,int> ans;
        while(true){
            if(mat[a][b]==0){
                move(a,b,d);
            }
            else {
                mat[a][b]=0;d++;
                d%=4;
                move(a,b,d);
            }
            if(a<R && a>=0 && b<C && b>=0)ans={a,b};
            else break;
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends