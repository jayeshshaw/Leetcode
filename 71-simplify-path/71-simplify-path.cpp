class Solution {
public:
    string simplifyPath(string p) {
        vector<string> v(2000,"meenal");
        int point=-1;
        for(int i=0;i<p.size();i++){
            if(p[i]=='/')continue;
            else if(p[i]=='.'){
                int d=0;string ss="";
                while(i<p.size() && p[i]!='/'){d++;ss+=p[i];i++;}
                // cout<<d<<" "<<endl;
                if(d==1)continue;
                if(d==2 && point>=0)point--;
                else if(d>2)v[++point]=ss;
            }
            else {
                string ss="";
                while(i<p.size() && p[i]!='/'){ss+=p[i++];}
                v[++point]=ss;
            }
        }
        
        string st="/";
        
        for(int i=0;i<point;i++){
            st+=v[i];
            st+='/';
        }
       if(point>=0) st+=v[point];
        return st;
    }
};