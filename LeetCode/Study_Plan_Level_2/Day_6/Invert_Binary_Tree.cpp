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
//      Time Complexity  : O(N)
//      Space Complexity : O(1)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //  Base case
        if(root == nullptr) return root;
        
        if(root->left == nullptr && root->right == nullptr)    return root;
        
        //  Otherwise swap left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        //  Apply the same on left & right subtree
        invertTree(root->left);
        invertTree(root->right);
        
        //  Return the inverted tree
        return root;
    }
};