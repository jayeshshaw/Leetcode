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
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)return 0;
        queue<TreeNode*> q;
        vector<int> temp;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* k=q.front();
            q.pop();
            if(k==NULL){
                v.push_back(temp);
                temp.resize(0);
                if(q.size()>0)q.push(NULL);
            }
            else{
                temp.push_back(k->val);
                if(k->left)q.push(k->left);
                if(k->right)q.push(k->right);
            }
        }
        
        return accumulate(v[v.size()-1].begin(),v[v.size()-1].end(),0);
    }
};