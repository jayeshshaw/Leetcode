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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root=maketree(nums,0,nums.size()-1);
        return root;
    }
    
    TreeNode* maketree(vector<int>& nums,int s,int e){
        if(s>e)
            return NULL;
        int mid = (s + e)/2;
        TreeNode *root = newNode(nums[mid]);
        root->left=maketree(nums,s,mid-1);
        root->right=maketree(nums,mid+1,e);
        return root;
    }
    
    TreeNode* newNode(int data)
        {
            TreeNode* node = new TreeNode();
            node->val = data;
            node->left = NULL;
            node->right = NULL;

            return node;
        }
};