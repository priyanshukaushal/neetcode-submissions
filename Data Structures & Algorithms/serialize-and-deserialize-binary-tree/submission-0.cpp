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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "N";
        string ans = "";
        ans.append(to_string(root->val));
        ans.append(",");
        ans.append(serialize(root->left));
        ans.append(",");
        ans.append(serialize(root->right));
        return ans;
    }

    int i = 0;

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(i >= data.length()) return NULL;
        if(data[i] == 'N') {
            i += 2;
            return NULL;
        }
        int j = i;
        while(j < data.length() && data[j] != ',') j++;
        j--;
        TreeNode * root = new TreeNode(stoi(data.substr(i,j-i+1)));
        i = j+2;
        root->left = deserialize(data);
        root->right = deserialize(data);
        return root;
    }
};
