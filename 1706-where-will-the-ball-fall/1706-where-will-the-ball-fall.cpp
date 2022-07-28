class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int x=0,y=i;
            bool done=false;
            while(x<m){
                // cout<<i<<" "<<x<<" "<<y<<"..."<<endl;
                if(grid[x][y]==1 && (y==n-1 || grid[x][y+1]==-1)){
                    ans.push_back(-1);
                    // cout<<i<<" "<<x<<" "<<y<<endl; 
                    done=true;break;
                }
                if(grid[x][y]==-1 && (y==0 || grid[x][y-1]==1)){
                    ans.push_back(-1);
                    // cout<<i<<" "<<x<<" "<<y<<endl;
                    done=true;break;
                }
                
                if(grid[x][y]==1){x++,y++;}
                else{ x++,y--;}
            }
            if(!done)
            ans.push_back(y);
        }
        return ans;
    }
};