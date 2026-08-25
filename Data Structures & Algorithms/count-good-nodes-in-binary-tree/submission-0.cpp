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
        mx = max(root->val,mx);
        int left = 0,right=0;
        if(root->left && root->left->val>=mx){
            left = 1 + solve(root->left,mx);
        }else left =solve(root->left,mx);
         if(root->right && root->right->val>=mx){
            right = 1 + solve(root->right,mx);
        }else right = solve(root->right,mx);
        return left+right;
    }

    int goodNodes(TreeNode* root) {
        return 1+solve(root,INT_MIN);
    }
};
