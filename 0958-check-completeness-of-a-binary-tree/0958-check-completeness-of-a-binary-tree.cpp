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
    vector<vector<int>> v;
    void f (TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        
        while(q.size()>0){
            auto t=q.front();
            q.pop();
            if(t==NULL){
                v.push_back(temp);
                temp.clear();
                if(q.size()>0)q.push(NULL);
            }
            else{
                temp.push_back(t->val);
                if(t->left==t && t->right==t)continue;
                TreeNode* n=new TreeNode(-1);n->left=n;n->right=n;
                if(t->left)q.push(t->left);
                else q.push(n);
                if(t->right)q.push(t->right);
                else q.push(n);
            }
        }
    }
    
public:
    bool isCompleteTree(TreeNode* root) {
        f(root);
        
        // for(auto i: v){
        //     for(auto j: i)cout<<j<<" ";
        //     cout<<endl;
        // }
        
        v.pop_back();
        for(int i=0;i<v.size();i++){
            if(i==v.size()-1){
                int j=v[i].size()-1;
                // for(auto ele: v[i])cout<<ele<<" ";
                while(j>=0 && v[i][j]==-1)j--;
                while(j>=0){
                    if(v[i][j--]==-1)return 0;
                }
            }
            
            else{
                for(auto ele: v[i])if(ele==-1)return 0;
            }
        }
        return 1;
    }
};