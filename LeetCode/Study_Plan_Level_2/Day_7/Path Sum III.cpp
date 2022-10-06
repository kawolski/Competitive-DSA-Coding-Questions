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
//      Time Complexity  : O(N^2)
//      Space Complexity : O(N)
class Solution {
public:
    //  Fucntion to find all paths starting from root having SUM == targetSum
    int helper(TreeNode* root,long long int targetSum){
        if(root == nullptr) return 0;
        int to_left = helper(root->left,targetSum-root->val);
        int to_right = helper(root->right,targetSum-root->val);
        return to_left + to_right + (root->val == targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        //  Find all paths starting from root
        int from_root = helper(root,targetSum);
        //  Find all paths starting from root->right
        int from_left = pathSum(root->left,targetSum);
        //  Find all paths starting from root->left
        int from_right = pathSum(root->right,targetSum);
        //  Return total possible paths for tree/subtree under root
        return from_root + from_left + from_right;
    }
};