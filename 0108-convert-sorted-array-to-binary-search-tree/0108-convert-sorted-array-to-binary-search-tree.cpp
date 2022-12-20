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
    TreeNode* sortedArrayToBST(vector<int>& v, int l=0, int r=1e9) {
        if(r==1e9)r=v.size()-1;
        if(r<l)return NULL;
        int mid=l+(r-l)/2;
        TreeNode* n=new TreeNode(v[mid]);
        n->left=sortedArrayToBST(v,l,mid-1);
        
        n->right=sortedArrayToBST(v,mid+1,r);
        return n;
    }
};