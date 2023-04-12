class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){continue;}
            string p;
            
            while(i<path.size() && path[i]!='/')p+=path[i++];
            i--;
            if(p==".."){
                if(v.size()==0)continue;
                v.pop_back();
            }
            else if(p=="."){
                continue;
            }
            else v.push_back(p);
        }
        // for(auto i: v)cout<<i<<" ";
        string ans="/";
        int i=0;
        for(;i<v.size();i++){
            ans+=v[i];
            ans+='/';
        }
        if(ans.size()>1 && ans.back()=='/')ans.pop_back();
        return ans;
    }
};