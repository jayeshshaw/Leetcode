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
    vector<int> v,vv;
    int p=0;
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        
        for(int i=v.size()-2;i>=0;i--){
            v[i]=v[i]+v[i+1];
        }
        changeval(root);
        return root;
    }
    
    void changeval(TreeNode* r){
        if(!r)return;
        changeval(r->left);
        r->val=v[p++];
        changeval(r->right);
    }
    void inorder(TreeNode* r){
        if(!r)return;
        inorder(r->left);
        v.push_back(r->val);
        inorder(r->right);
    }
};