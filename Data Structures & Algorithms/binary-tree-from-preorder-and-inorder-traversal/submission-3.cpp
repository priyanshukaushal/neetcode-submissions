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

    unordered_map<int,int> inorderIndexMap;

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if(ps > pe || is > ie) return NULL;
        int currVal = preorder[ps];
        int index = inorderIndexMap[currVal];

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
        int n = inorder.size();
        for(int i = 0; i<n; i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        return helper(preorder,inorder,0,n-1,0,n-1);
    }
};
