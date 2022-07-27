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
    
    void preorder(vector<int> &v, TreeNode* t){
        if(t==NULL)return ;
        v.push_back(t->val);
        preorder(v,t->left);
        preorder(v,t->right);
    }
    
    void flatten(TreeNode* root) {
        TreeNode* t=root;
        vector<int> pre;
        preorder(pre,t);
        int i=0;
        t=root;
        while(i<pre.size() && t){
            t->val=pre[i++];
            t->left=NULL;
           if(t->right) t=t->right;
            else break;
        }
        while(i<pre.size()){
            TreeNode* n=new TreeNode;
            n->val=pre[i++];
            t->right=n;
            t=t->right;
        }
        // return root;
    }
};