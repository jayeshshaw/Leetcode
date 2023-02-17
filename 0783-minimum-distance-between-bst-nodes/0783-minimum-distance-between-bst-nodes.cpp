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
    void f(TreeNode* r){
        if(!r)return;
        f(r->left);
        v.push_back(r->val);
        f(r->right);
    }
    int minDiffInBST(TreeNode* root) {
        f(root);
        sort(begin(v),end(v));
        int ans=INT_MAX;
        for(int i=1;i<v.size();i++){
            ans=min(ans,v[i]-v[i-1]);
        }
        return ans;
    }
};