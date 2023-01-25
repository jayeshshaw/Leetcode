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
private:
    
    int mx=-1;
    int node=0;
    void dfs(TreeNode* r, int d){
        if(!r)return;
        // cout<<r->val<<" "<<d<<endl;
        dfs(r->left,d+1);
        if(d>mx){
            mx=d;node=r->val;
        }
        dfs(r->right,d+1);
    }
    
    
public:
    int findBottomLeftValue(TreeNode* root) {
        int d=0;
        dfs(root,d);
        return node;
    }
};