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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        vector<vector<int>> lot=levelOrder(root);
        for(auto i: lot){
            long double abhi=0;
            double sz=i.size();
            for(auto j: i)abhi+=j*1.000000/sz;
            ans.push_back(abhi);
        }
        return ans;
    }
};