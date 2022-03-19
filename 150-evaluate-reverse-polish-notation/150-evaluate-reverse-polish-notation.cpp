class Solution {
public:
    vector<string> v;
    int evaluate_postfix(){
        stack<string> st;
        for(auto i: v){
            if(i=="+" || i=="-" || i=="*" || i=="/"){
                int a=stoi(st.top()); st.pop();
                int b=stoi(st.top()); st.pop();
                if(i=="+")st.push(to_string(b+a));
                if(i=="-")st.push(to_string(b-a));
                if(i=="*")st.push(to_string(b*a));
                if(i=="/")st.push(to_string(b/a));
            }
            else{
                st.push(i);
            }
        }
        return stoi(st.top());
    }
    int evalRPN(vector<string>& tokens) {
        
        for(auto i: tokens)v.push_back(i);
        return evaluate_postfix();
    }
};