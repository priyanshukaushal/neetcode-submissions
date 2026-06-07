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
    int findIndex(int val, vector<int>& inorder, int is, int ie) {
        int i = is;
        while(i <= ie) {
            if(inorder[i] == val) return i;
            i++;
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if(ps > pe || is > ie) return NULL;
        int currVal = preorder[ps];
        int index = findIndex(currVal, inorder, is, ie);

        int leftInStart = is;
        int leftInEnd = index-1;
        int rightInStart = index+1;
        int rightInEnd = ie;

        int leftSize = leftInEnd-leftInStart+1;

        int leftPreStart = ps+1;
        int leftPreEnd = leftPreStart+leftSize-1;
        int rightPreStart = leftPreEnd+1;
        int rightPreEnd = pe;

        TreeNode * root = new TreeNode(currVal);
        root->left = helper(preorder,inorder,leftPreStart,leftPreEnd,leftInStart,leftInEnd);
        root->right = helper(preorder,inorder,rightPreStart,rightPreEnd,rightInStart,rightInEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
