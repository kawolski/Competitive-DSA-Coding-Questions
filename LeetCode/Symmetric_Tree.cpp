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
//      where N = total nodes in the tree
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        //  Base cases
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return true;
        if((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr))  return false;
        
        //  Traverse left to right for left subtree
        queue<TreeNode*> l2r;
        l2r.push(root->left);
        
        //  Traverse right to left for right subtree
        queue<TreeNode*> r2l;
        r2l.push(root->right);
        
        //  Loop until symmetry is broken or queue is depleted
        while(l2r.empty() == false && r2l.empty() == false){
            auto left = l2r.front();
            l2r.pop();
            auto right = r2l.front();
            r2l.pop();
            
            //  Check for symmetry failure
            if(left != nullptr && right != nullptr && left->val != right->val)
                return false;
            else if((left != nullptr && right == nullptr) || (left == nullptr && right != nullptr))
                return false;
            //  Tree Symmetric till now
            //  Left subtree insertions
            if(left != nullptr)
                l2r.push(left->left),l2r.push(left->right);;
            //  Right subtree insertions
            if(right != nullptr)
                r2l.push(right->right),r2l.push(right->left);
            
        }
        //  No symmetry failure found
        //  Check for total elements in left and right subtree
        if(l2r.empty() == true && r2l.empty() == true)
            return true;
        else
            return false;
    }
};