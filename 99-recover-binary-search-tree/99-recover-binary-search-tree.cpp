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
    vector<int> v;
    int i=0;
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(v.begin(),v.end());
        inorderfill(root);
    }
    void inorder(TreeNode* t){
        if(!t)return;
        inorder(t->left);
        v.push_back(t->val);
        inorder(t->right);
    }
    void inorderfill(TreeNode* t){
        if(!t)return;
        inorderfill(t->left);
        t->val=v[i++];
        inorderfill(t->right);
    }
};