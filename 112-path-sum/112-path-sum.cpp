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
    
//     bool f(TreeNode* root, int t){
        // if(!root)return t==0;
//         bool a=f(root->left,t-root->val);
//         bool b=f(root->right,t-root->val);
//         return a or b;
        
//     }
    
    bool hasPathSum(TreeNode* root, int t) {
        if(!root)return 0;
        if(!root->left && !root->right)return t==root->val;
        bool a=hasPathSum(root->left,t-root->val);
        bool b=hasPathSum(root->right,t-root->val);
        return a or b;
    }
};