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
class BSTIterator {
private:        //  Encapsulation
    stack<TreeNode*> st;
    //  In Order Traversal
    void iot_traversal(TreeNode* root){
        for(;root != nullptr;st.push(root),root=root->left);
    }
public:         //  Abstraction
    BSTIterator(TreeNode* root) {
        //  Empty the IOT
        while(!st.empty())
            st.pop();
        //  Create In-Order Traversal
        iot_traversal(root);
    }
    
    //      Time Complexity : O(1)
    int next() {
        //  Get & Pop the next element
        TreeNode* next = st.top();
        st.pop();
        //  Continue & Save next traversal elements
        iot_traversal(next->right);
        //  Return required value
        return next->val;
    }
    
    //      Time Complexity : O(1)
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */