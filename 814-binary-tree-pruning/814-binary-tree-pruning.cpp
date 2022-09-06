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
    bool removeNodes(TreeNode* root){
        if(!root)return 0;
        if(root->left==NULL && root->right==NULL)return root->val==1;
        bool a=removeNodes(root->left) ;
        bool b=removeNodes(root->right);
        if(!a){root->left=NULL;}
        if(!b){root->right=NULL;}
        if(a || b || root->val==1)return 1;
        return 0;
        
    }
    
    TreeNode* pruneTree(TreeNode* root) {
         if(removeNodes(root))return root;
        else return NULL;
    }
};