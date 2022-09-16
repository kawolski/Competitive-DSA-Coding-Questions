/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //     Time Complexity  : O(N)
 //     Space Complexity : O(1)
 int solve(TreeNode *root,int &ans){
    // Nullptr
    if(!root)
        return 0;
    //  Either maxSumPath exists on left subtree
    int left = solve(root->left,ans);
    //  Or maxSumPath exists on right subtree
    int right = solve(root->right,ans);
    //  Or maxSumPath only consists of current node
    //  Or maxSumPath consists of left subtree + current node or right subtree + current node
    int m1 = max(root->val,root->val + max(left,right));
    //  Or maxSumPath consists of left subtree + current node + right subtree
    int m2 = max(root->val + left + right,m1);
    ans = max(ans,m2);
    return m1;
 }

int Solution::maxPathSum(TreeNode* A) {
    int ans = INT_MIN;
    solve(A,ans);
    return ans;
}
