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

    int solve(TreeNode* root, int mx){
        if(!root){
            return 0;
        }
        int count = 0;
        if(mx<=root->val){
            count=1;
        }
        mx = max(root->val,mx);
        count += solve(root->left,mx);
        count += solve(root->right,mx);
        
        return count;
    }

    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};
