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

    bool check(TreeNode* root, TreeNode* subRoot){
        bool left = 0, right = 0;
        if(!subRoot && !root) return 1;
        if(!subRoot || !root) return 0;

        if(root->val != subRoot->val) return 0;
        left = check(root->left, subRoot->left);
        right = check(root->right, subRoot->right);
        return right && left;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root->val==subRoot->val){
            if(check(root,subRoot))
                return 1;
        }
        if(!root) return 0;
        bool left = 0, right = 0;
        if(root->right){
            right = isSubtree(root->right, subRoot);
        }
        if(root->left){
            left = isSubtree(root->left, subRoot);
        }
        return  right || left ;
    }
};
