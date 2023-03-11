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
    unordered_map<int,vector<int>> mp;
    TreeNode* maketree(int root){
        if(root==-1)return NULL;
        
        TreeNode* n=new TreeNode(root);
        
        n->left=maketree(mp[root][0]);
        n->right=maketree(mp[root][1]);
        return n;
    }
    
    
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int> isroot;
        for(auto i: descriptions){
            if(mp.find(i[0])==mp.end())mp[i[0]].push_back(-1),mp[i[0]].push_back(-1);
            if(mp.find(i[1])==mp.end())mp[i[1]].push_back(-1),mp[i[1]].push_back(-1);
            
            if(i[2]==1)mp[i[0]][0]=i[1];
            else mp[i[0]][1]=i[1];
            
            isroot[i[1]]=-1;
            if(isroot[i[0]]!=-1)isroot[i[0]]=1;
        }
        int r;
        for(auto i: isroot){
            if(i.second==1){r=i.first;break;}
        }
        // cout<<r<<" ";
        return maketree(r);  
        // return NULL;
    }
};