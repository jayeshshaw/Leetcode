class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans1="",ans2="";
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){st.push(s[i]);}
            else if(s[i]==')' && st.size()>0 && st.top()=='('){st.pop();}
            else if(s[i]==')'){s.erase(s.begin()+i);i--;}
        }
        cout<<s;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')'){st.push(s[i]);}
            else if(s[i]=='(' && st.size()>0 && st.top()==')'){st.pop();}
            else if(s[i]=='('){s.erase(s.begin()+i);}
        }
        
        return s;
    }
};