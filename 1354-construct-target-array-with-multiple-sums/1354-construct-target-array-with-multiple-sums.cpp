class Solution {
public:
    bool isPossible(vector<int>& target) {
         priority_queue <int> pq;
         long sum=0;
         for(auto i: target)sum+=i,pq.push(i);
    
         while(pq.top() != 1){
            int x= pq.top();
            pq.pop();
            sum -=x;
            if(x <= sum || sum <=0) return false;
            x %= sum;
            sum += x;
            if(x!=0)pq.push(x);
            else pq.push(sum);
         }
         return true;
    }
};