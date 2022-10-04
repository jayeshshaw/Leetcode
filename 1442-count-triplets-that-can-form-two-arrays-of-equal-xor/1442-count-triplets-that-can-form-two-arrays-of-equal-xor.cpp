class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int triplets=0;
        int size=arr.size();
        for(int i=0;i<size;i++){
            int j=i+1;
            int subarray_xor=arr[i];
            while(j<size){
                subarray_xor^=arr[j];
                if(subarray_xor==0)triplets+=j-i;
                j++;
            }
            // cout<<i<<" "<<triplets<<endl;
        }
        return triplets;
    }
};