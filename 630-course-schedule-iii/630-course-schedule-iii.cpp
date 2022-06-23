class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& c) {
        sort(c.begin(),c.end(),cmp);
        priority_queue<int> pq;
        int time =0;
        for(int i =0;i<c.size();i++){
			if(time + c[i][0] <= c[i][1]){
                pq.push(c[i][0]);
                time += c[i][0];
            }else if(!pq.empty() && c[i][0] <= pq.top()){
                time -= pq.top();
                pq.pop();
                time += c[i][0];
                pq.push(c[i][0]);
            }
        }
        
        return pq.size(); 
    }
};