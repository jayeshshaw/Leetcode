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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        if(!root->left && !root->right)return root;
        
        if(!root->left){
            root->left=root->right;
            root->right=NULL;
            invertTree(root->left);
            return root;
        }
        
        if(!root->right){
            root->right=root->left;
            root->left=NULL;
            invertTree(root->right);
            return root;
        }
        
        TreeNode* t=root->left;
        root->left=root->right;
        root->right=t;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};