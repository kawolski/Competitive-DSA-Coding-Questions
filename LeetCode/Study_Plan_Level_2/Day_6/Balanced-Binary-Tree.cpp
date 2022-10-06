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
//      Space Complexity : O(N)
class Solution {
public:
    //  Function to find height of the Node/Subtree
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        //  Find height of left node
        int left = height(root->left);
        //  Find height of right node
        int right = height(root->right);
        //  Return 1 + longest tail will be considered for determining height
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        //  Base case
        if(root == nullptr) return true;
        //  Find height of left sub-tree
        int left = height(root->left);
        //  Find height of right sub-tree
        int right = height(root->right);
        //  If difference of heights is more than 1, the tree is not balanced
        if(abs(left-right) > 1) return false;
        //  If balanced, check if children nodes are balanced
        else                    return (isBalanced(root->left) && isBalanced(root->right));
    }
};