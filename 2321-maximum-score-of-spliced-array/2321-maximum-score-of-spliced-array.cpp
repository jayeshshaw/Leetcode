class Solution {
public:
    int calc(vector<int> v){
        int c=0;
        int mx=-1e9;
        for(auto i: v){
            c=max(i,c+i);
            mx=max(mx,c);}
            return mx;
        
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> v(n,0),v2=v;
        int s1=0,s2=0;
        
        for(int i=0;i<n;i++){s1+=nums1[i];s2+=nums2[i];v[i]=nums2[i]-nums1[i];v2[i]=nums1[i]-nums2[i];}
        
        int f=max(s1+calc(v),s2-calc(v));
        int s=max(s2+calc(v2),s1-calc(v2));
        return max(f,s);        
    }
    
};