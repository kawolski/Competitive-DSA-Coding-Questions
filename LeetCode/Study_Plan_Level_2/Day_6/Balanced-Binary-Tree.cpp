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
    int solve(TreeNode* root,int &maxDiff){
        if(root == nullptr) {
            maxDiff = max(maxDiff,0);   return 0;
        }
        if(root->left == nullptr && root->right == nullptr) {
            maxDiff = max(maxDiff,0);   return 1;
        }
        //  Find the difference of left & right subtree height
        int left = solve(root->left,maxDiff);
        int right = solve(root->right,maxDiff);
        //  Update maxDifference for current node
        maxDiff = max(maxDiff,abs(left-right));
        //  Return max height of subtree, left or right, and include current node
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        //  Solve By :
        //  Time Complexity  : O(N)
        //  Space Complexity : O(log N)
        int maxDiff = INT_MIN;
        solve(root,maxDiff);
        if(maxDiff < 2) return true;
        else                        return false;
        
        //  Solve By :
        //  Time Complexity  : O(N^2)
        //  Space Complexity : O(log N)
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