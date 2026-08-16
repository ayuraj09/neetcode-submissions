class Solution {
    int diameter = 0;

    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diameter;
    }
};