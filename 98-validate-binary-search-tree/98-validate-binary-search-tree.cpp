/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isbst(TreeNode* root,int low,int high){
        if(!root)return true;
        if(root->val<low || root->val>high)return false;
        
        bool a=false,b=false;
        
        if(root->val==low ){
            if( !root->left )a=true;
        }
        else a=isbst(root->left, low, root->val-1);
        
        
        if(root->val==high){
            if(!root->right ) b=true;
        }
        else b=isbst(root->right, root->val+1,high);
        
        return a&&b;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        return isbst(root,INT_MIN,INT_MAX);
    }
};