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
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        int temp = max(root->val,max(left,right)+root->val);
        ans = max(ans,max(left + right + root->val,temp));
        // cout<<ans<<" ";
        return temp;
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
