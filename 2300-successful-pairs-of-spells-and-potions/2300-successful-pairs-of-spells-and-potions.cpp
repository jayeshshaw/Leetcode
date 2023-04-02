class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long suc) {
          // sort(s.begin(),s.end());
        sort(p.begin(),p.end());
        vector<int> v;
        long long temp,temp2;
        
        for(long long int i=0;i<s.size();i++){
            
            long long int l=0,r=p.size()-1,mid;
            int ans=0;
//             while(l<=r){
                
//                 mid=l+(r-l)/2;
//                 temp=p[mid]*s[i];
//                 if(temp>=suc){
//                     if(mid>0){
//                         temp2=p[mid-1]*s[i];
//                         if(temp2>=suc)r=mid-1;
//                         else {ans=p.size()-mid;break;}
//                     }
//                     else {ans=p.size();break;}
//                 }
//                 else l=mid+1;
                    
//             }
            long long k=ceil(double(suc*1.0/s[i])); 
            ans=lower_bound(p.begin(),p.end(),k)-p.begin();
            // cout<<ans<<" ";
//             if(ans==-1094795586)v.push_back(0);
//             else 
            
                v.push_back(p.size()-ans);
            
        } 
        cout<<endl;
        return v;
    }
};