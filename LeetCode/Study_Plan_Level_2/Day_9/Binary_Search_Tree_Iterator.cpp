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
    int index;
    vector<int> iot;
    //  In Order Traversal
    void iot_traversal(TreeNode* root){
        //  Base Case
        if(root == nullptr) return;
        //  Left
        iot_traversal(root->left);
        //  Node
        iot.push_back(root->val);
        //  Right
        iot_traversal(root->right);
    }
public:         //  Abstraction
    BSTIterator(TreeNode* root) {
        //  Empty the IOT
        iot.clear();
        //  Create In-Order Traversal
        iot_traversal(root);
        //  Set current Index
        index = -1;
    }
    
    //      Time Complexity : O(1)
    int next() {
        if(hasNext())
            return iot[++index];
        else
            return -1;
    }
    
    //      Time Complexity : O(1)
    bool hasNext() {
        return (index+1) < iot.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */