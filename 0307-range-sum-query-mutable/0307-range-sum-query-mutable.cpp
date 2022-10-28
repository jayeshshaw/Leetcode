class NumArray {
public:
    vector<int> fen;
    vector<int> v;
    void update(int i, int val) {
        i++;
        int k=v[i];
        v[i]=val;
        val=val-k;
        while(i<fen.size()){fen[i]+=val;i=i+(i&(-i));}
        // for(auto i: v)cout<<i<<" ";
        // cout<<endl;
    }
    
    int sumt(int i){int sm=0;while(i>0){sm+=fen[i];i=i-(i&(-i));} return sm;}

    
    int sumRange(int left, int right) {
        return sumt(right+1)-sumt(left);
    }
    
    NumArray(vector<int>& nums) {
        int n=nums.size();
        v.resize(n+1,0);
        fen.resize(n+1,0);
        for(int i=0;i<n;i++){
            // cout<<i<<" "<<nums[i]<<endl;
            update(i,nums[i]);
        }
    }
    
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */