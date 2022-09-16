/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //     Time Complexity  : O(N)
 //     Space Complexity : O(N)
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    //  Select the first Node ie : the smallest Node
    ListNode* head;
    if(A->val < B->val){
        head = A;
        A = A->next;
    }
    else{
        head = B;
        B = B->next;
    }
    
    ListNode* temp = head;
    
    while(A != nullptr && B != nullptr){
        //  Compare the first links of both the chains and connect with the smaller one
        if(A->val < B->val){
            temp->next = A;
            A = A->next;
        }
        else{
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }
    //  Check for remaining nodes
    while(A != nullptr){
        temp->next = A;
        A = A->next;
        temp = temp->next;
    }
    while(B != nullptr){
        temp->next = B;
        B = B->next;
        temp = temp->next;
    }
    //  Return head
    return head;
}
