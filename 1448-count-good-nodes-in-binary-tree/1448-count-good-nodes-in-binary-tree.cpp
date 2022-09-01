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
    
    int goodNodes(TreeNode* root,int mx=-1e9) {
        if(!root)return 0;
        if(root->val>=mx){
            mx=root->val;
            return 1+ goodNodes(root->left,mx)+goodNodes(root->right,mx);
        }
        return goodNodes(root->left,mx)+ goodNodes(root->right,mx); 
    }
};