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
//      Space Complexity : O(2^(N-1))
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //  Base case : root is null
        if(root == nullptr)
            return {};
        
        //  Initialization of queue
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        
        vector<int> res;
        pair<TreeNode*,int> front = {nullptr,0};
        
        //  Initiate loop
        while(q.empty() == false){
            
            //  If the front of the queue is at the begining of next tree level
            if(front.first != nullptr && front.second != q.front().second)
                res.push_back(front.first->val);
            
            //  Get & Pop the front
            front = q.front();
            q.pop();
            
            //  Check for left node
            if(front.first->left != nullptr)
                q.push({front.first->left,front.second+1});
            //  Check for right node
            if(front.first->right != nullptr)
                q.push({front.first->right,front.second+1});
        }
        
        //  Push the last remaining value
        res.push_back(front.first->val);
        
        return res;
    }
};