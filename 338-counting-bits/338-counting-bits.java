class Solution {
    public int[] countBits(int n) {
        int count;
        int j=0;
        int arr[]=new int[n+1];
       for(int i=0;i<=n;i++)
       {   count=0;
           
            int x=i;
           while(x!=0)
           {
             if((x&1)==1) 
                 count++;
               x=x>>1;
           }
        arr[j++]=count;
       }
        return arr;
    }
}