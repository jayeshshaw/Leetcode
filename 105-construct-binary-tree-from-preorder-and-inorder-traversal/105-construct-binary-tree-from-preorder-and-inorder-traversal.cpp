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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int i=0;
        return f(i,0,n-1,preorder,inorder);
    }
    
    TreeNode* f(int &i, int left, int right, vector<int> &pre, vector<int> &in){
        if(left>right)return NULL;
        
        int pivot=left;
        while(in[pivot]!=pre[i])pivot++;
        i++;
        TreeNode* nnode=new TreeNode(in[pivot]);
        nnode->left= f(i,left,pivot-1,pre,in);
        nnode->right= f(i,pivot+1,right,pre,in);
        
        return nnode;
    }
};