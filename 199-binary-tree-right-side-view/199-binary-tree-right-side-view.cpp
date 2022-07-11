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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int last=0;
        while(!q.empty()){
            TreeNode* t=q.front();q.pop();
            
            if(t==NULL){
                ans.push_back(last);
                if(q.size()>0) q.push(NULL);
            }
            else{
                last=t->val;
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
        }
        return ans;
    }
};