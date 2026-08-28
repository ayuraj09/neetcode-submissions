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

    TreeNode* makeTree(vector<int> &s, int &idx){
        if(idx>=s.size() || s[idx]==1001){
            idx++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(s[idx]);
        idx++;
        node->left = makeTree(s,idx);
        node->right = makeTree(s,idx);
        return node;
    }

    TreeNode* deserialize(string data) {
        TreeNode* head = new TreeNode();
        vector<int> s;
        for(int i=0;i<data.length();i++){
            if(data[i]=='#'){
                string temp = "";
                i++;
                while(data[i]!='#'){
                    temp+=data[i];
                    i++;
                }
                int val = stoi(temp);
                s.push_back(val);
                // i++;
            }
            if(data[i]=='@'){
                s.push_back(1001);
            }
        }
        int idx = 0;
        return makeTree(s,idx);
    }
};
