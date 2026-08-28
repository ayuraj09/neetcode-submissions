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

class Codec {
public:

    void makeString(TreeNode* root, string &s){
        if(!root){
            s+="@";
            return;
        }
        s+="#";
        s+=to_string(root->val);
        s+="#";

        makeString(root->left,s);
        makeString(root->right,s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        makeString(root,s);
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.

    TreeNode* makeTree(string &data, int &idx) {
        // Null node
        if (data[idx] == '@') {
            idx++;
            return nullptr;
        }

        idx++; 
        string temp;

        while (data[idx] != '#') {
            temp += data[idx];
            idx++;
        }

        idx++; 

        TreeNode* node = new TreeNode(stoi(temp));

        node->left = makeTree(data, idx);
        node->right = makeTree(data, idx);

        return node;
    }

    TreeNode* deserialize(string data) {
        int idx = 0;
        return makeTree(data, idx);
    }
};

