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
    vector<vector<int>> r;
    vector<int> t;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)return r;
        alr2l(root,targetSum);
        return r;
    }
    
     void alr2l(TreeNode* root,int s){
        
         if(!root)return;
         t.push_back(root->val);
         
         if (!(root -> left) && !(root -> right) && s == root -> val)
            r.push_back(t);
         
        
         alr2l(root->left,s-root->val);
         alr2l(root->right,s-root->val);
         t.pop_back();
    }
};