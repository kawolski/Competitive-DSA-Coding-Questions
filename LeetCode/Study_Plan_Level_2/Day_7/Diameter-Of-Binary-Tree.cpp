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
    //  Function to find longest path which includes current node
    int solve(TreeNode* root,int &res){
        if(root == nullptr) return 0;
        //  Lenght of left longest
        int left = solve(root->left,res);
        //  Length of right longest
        int right = solve(root->right,res);
        //  Update ans with maximum of ans , longest left + longest right
        res = max(res,left + right);
        //  And return longest chain till yet
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //  Ans variable
        int res = 0;
        //  Function call
        solve(root,res);
        return res;
    }
};