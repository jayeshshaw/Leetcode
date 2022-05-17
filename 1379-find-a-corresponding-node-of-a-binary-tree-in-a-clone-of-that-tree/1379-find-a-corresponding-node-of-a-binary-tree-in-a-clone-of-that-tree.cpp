/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void makevec(TreeNode* t,vector<pair<TreeNode*, int>> &v){
        if(!t)return;
        makevec(t->left,v);
        v.push_back({t,t->val});
        makevec(t->right,v);
        
    }
    
    TreeNode* getTargetCopy(TreeNode* h1, TreeNode* h2, TreeNode* target) {
        TreeNode* ans,*t1=h1,*t2=h2;
        vector<pair<TreeNode*, int>> v1,v2;
        makevec(t1,v1);
        makevec(t2,v2);
        for(int i=0;i<v1.size();i++){
            if(v1[i].first==target)return v2[i].first;
        }
        return NULL;
    }
};