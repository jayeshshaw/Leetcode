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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> bfs;
        if(!root)return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> level;
        while(q.size()>0){
            TreeNode* top=q.front();
            q.pop();
            if(top==NULL){
                bfs.push_back(level);
                level.resize(0);
                if(q.size()==0)break;
                q.push(NULL);
            }
            else{
                level.push_back(top->val);
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
        }
        
        for(int i=1;i<bfs.size();i+=2)reverse(begin(bfs[i]),end(bfs[i]));
        
        return bfs;
    }
};