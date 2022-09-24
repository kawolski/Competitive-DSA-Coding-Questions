/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//      Time Complexity  : O(Nlog(N))
//      Space Complexity : O(1)
class Solution {
public:
    ListNode* merge_list(ListNode *l1,ListNode *l2){
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        while(l1){
            temp->next = l1,temp = temp->next;
            l1 = l1->next;
        }
        while(l2){
            temp->next = l2,temp = temp->next;
            l2 = l2->next;
        }
        return result->next;
    }
    ListNode* sortList(ListNode* head) {
        //  Base case : List cotaines 0 or 1 node
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *temp = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        
        //  Turtle-Hare Algorithm  (Finding the middle element)
        while(fast != nullptr && fast->next != nullptr){
            temp = slow;
            slow = slow->next;          //  Increment by 1
            fast = fast->next->next;    //  Increment by 2
        }
        temp->next = nullptr;           //  End of first left half
        
        ListNode *l1 = sortList(head);      //  left half recursive call
        ListNode *l2 = sortList(slow);      //  right half recursive call
        
        return merge_list(l1,l2);        
    }
};