class Solution {
public:
    
//     vector<vector<int>> getnextAndPreviousSmaller(vector<int> &heights){
//         int size=heights.size();
//         vector<vector<int>> nextAndPreviousSmaller(size,{-1,-1});
//         stack<vector<int>> st;
        
//         for(int i=0;i<size;i++){
//             if(st.size()==0){st.push({heights[i],i});continue;}
            
//             while(st.size()>0 && heights[i]<st.top()[0]){
//                 nextAndPreviousSmaller[st.top()[1]][0]=i;
//                 st.pop();
//             }
//         }
        
//         while(st.size()>0)st.pop();
        
//         for(int i=size-1;i>=0;i--){
//             if(st.size()==0){st.push({heights[i],i});continue;}
            
//             while(st.size()>0 && heights[i]<st.top()[0]){
//                 nextAndPreviousSmaller[st.top()[1]][1]=i;
//                 st.pop();
//             }
//         }
//         return nextAndPreviousSmaller;
//     }
    
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
};