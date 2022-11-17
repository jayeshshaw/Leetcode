/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(t!=NULL){
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                temp.push_back(t->val);
            }
            else{
                ans.push_back(temp);
                temp.resize(0);
                if(q.size()>0)q.push(NULL);
            }
        }
        return ans;
        
    }
    int minSwaps(vector<int> arr, int n)
{
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
 
    sort(arrPos, arrPos + n);
 
    vector<bool> vis(n, false);
 
    int ans = 0;
 
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || arrPos[i].second == i)
            continue;
 
        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
 
            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }
 
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }
 
    // Return result
    return ans;
}
    int minimumOperations(TreeNode* root) {
        vector<vector<int>> levels=levelOrder(root);
        int ans=0;
        for(auto i: levels)ans+=minSwaps(i,i.size());
        return ans;
    }
};