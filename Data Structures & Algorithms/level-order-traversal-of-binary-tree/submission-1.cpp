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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vector<vector<int>> ans;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int level = it.second;
            if(ans.size()==level){
                ans.push_back({});
            }
            ans[level].push_back(it.first->val);

            if(it.first->left){
                q.push({it.first->left,level+1});
            }
            if(it.first->right){
                q.push({it.first->right,level+1});
            }
        }
        return ans;
    }
};
