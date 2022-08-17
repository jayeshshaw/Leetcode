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
    int ans=0;
    int diameterOfBinaryTree(TreeNode* root)  {
        int k=dia(root);
        return ans;
        
    }
    
    int dia(TreeNode* root) {
        if(!root)return 0;
        int lh=dia(root->left);
        int rh=dia(root->right);
        ans=max(ans,lh+rh);
        return max(lh,rh)+1;
    }
};