/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //     Time Complexity  : O(N)
 //     Space Complexity : O(1)
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* left = nullptr;
    ListNode* right = nullptr;
    ListNode* head_left = nullptr;
    ListNode* head_right = nullptr;
    
    while(A){
        //  Compare value with B
        //  Add to left
        if(A->val < B){
            //  If left == nullptr
            if(left == nullptr){
                left = A;
                head_left = A;
            }
            else{
                left->next = A;
                left = left->next;
            }
        }
        //  Add to right
        else{
            //  If right == nullptr
            if(right == nullptr){
                right = A;
                head_right = A;
            }
            else{
                right->next = A;
                right = right->next;
            }
        }
        //  Move to next node
        A = A->next;
    }
    //  If there is a node with val < B
    if(head_left){
        //  Also If there are nodes with val >= B
        if(right){
            left->next = head_right;
            right->next = nullptr;
        }
        return head_left;
    }
    else
        return head_right;
}
