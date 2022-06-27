class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)nums.push_back(nums[i]);
        vector<int> v(nums.size(),0);
        stack<int> s;
        
        for(int i=v.size()-1;i>=0;i--){
            if(s.empty()){v[i]=-1,s.push(nums[i]);}
            
            if(!s.empty() && nums[i]<s.top()){
                v[i]=s.top(),s.push(nums[i]);
            }
            else if(!s.empty() && nums[i]>= s.top()){
                while(!s.empty() && nums[i]>= s.top())s.pop();
                
                if(s.empty())v[i]=-1;
                else v[i]=s.top();
                s.push(nums[i]);
            }
        }
        while(n--)v.pop_back();
        return v;
    }
};