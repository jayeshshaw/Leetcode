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
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        makevec(root,v);
        int a=0,b=v.size()-1;
        while(a<b){
            if(v[a]+v[b]==k)return true;
            if(v[a]+v[b]<k)a++;
            else if(v[a]+v[b]>k)b--;
        }
        return false;
    }
    void makevec(TreeNode* root, vector<int> &v){
        if(!root)return;
        makevec(root->left,v);
        v.push_back(root->val);
        makevec(root->right,v);
        return;
    }
};