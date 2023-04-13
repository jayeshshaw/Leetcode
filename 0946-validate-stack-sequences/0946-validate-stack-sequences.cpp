class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n=pushed.size();
        int a=0,b=0;
        while(a<n || b<n){
            if(st.size()==0 && a<n){
                st.push(pushed[a++]);
                continue;
            }
            else if(b<n && popped[b]==st.top())st.pop(),b++;
            else if(a<n)st.push(pushed[a++]);
            else return 0;
        }
        return st.size()==0;
    }
};