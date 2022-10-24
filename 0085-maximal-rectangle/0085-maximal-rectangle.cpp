class Solution {
public:
    
     vector<int> leftSmaller(vector<int> &arr, int n){
        stack<vector<int>> st;
        vector<int> nextSmallerArray(n,-1);
        for(int i=n-1;i>=0;i--){
            if(st.size()==0){st.push({arr[i],i});continue;}
            
            while(st.size()>0 && arr[i]<st.top()[0]) {
                vector<int> top=st.top();st.pop();
                nextSmallerArray[top[1]]=i;
            }       
            st.push({arr[i],i});
        }
        return nextSmallerArray;
    }
    
    vector<int> rightSmaller(vector<int> &arr, int n){
        stack<vector<int>> st;
        vector<int> nextSmallerArray(n,n);
        for(int i=0;i<n;i++){
            if(st.size()==0){st.push({arr[i],i});continue;}

            while(st.size()>0 && arr[i]<st.top()[0]) {
                vector<int> top=st.top();st.pop();
                nextSmallerArray[top[1]]=i;
            }       
            st.push({arr[i],i});
        }
        return nextSmallerArray;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        // vector<vector<int>> nextAndPreviousSmaller= getnextAndPreviousSmaller(heights);
        int n=heights.size();
        vector<int> next=rightSmaller(heights,n);
        vector<int> prev=leftSmaller(heights,n);
        
        int ans=0;
        for(int i=0;i<heights.size();i++){
            int here=(next[i]-prev[i]-1)*heights[i];
            ans=max(ans,here);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> heights(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')heights[j]++;
                else heights[j]=0;
            }
            // for(auto i: heights)cout<<i<<" ";
            // cout<<endl;
            ans=max(ans,largestRectangleArea(heights));
        }
        return ans;
    }
};