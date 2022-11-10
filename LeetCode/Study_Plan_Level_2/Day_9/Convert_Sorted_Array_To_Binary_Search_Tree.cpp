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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        function<TreeNode*(int,int)> solve = [&](int low, int high)->TreeNode*{
            //  Base case
            if(low > high)
                return nullptr;
            int mid = (low+high)/2;
            //  Make root node
            TreeNode* root = new TreeNode(nums[mid]);
            //  Get left node
            TreeNode* left = solve(low,mid-1);
                //  Connect to left node
                root->left = left;
            //  Get right node
            TreeNode* right = solve(mid+1,high);
                //  Connect to right node
                root->right = right;
            
            //  Return root
            return root;
            
        };
        
        return solve(0,nums.size()-1);
    }
};