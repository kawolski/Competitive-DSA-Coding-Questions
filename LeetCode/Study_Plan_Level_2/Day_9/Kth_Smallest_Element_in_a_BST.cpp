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
//      Space Complexity : O(log N)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        //  InOrder Traversal   :   L-N-R
        int ans = root->val;
        
        function<void(TreeNode*)> solve = [&](TreeNode* node)->void{
            if(k == 0 || node == nullptr)
                return;
            //  Left
            solve(node->left);
            //  Node
            k--;
            if(k == 0)
                ans = node->val;
            //  Right
            solve(node->right);
        };
        
        solve(root);
        
        return ans;
    }
};