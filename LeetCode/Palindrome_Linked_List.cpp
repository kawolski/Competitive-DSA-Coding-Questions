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
//      Time Complexity  : O(N)
//      Space Complexity : O(1)
class Solution {
public:
    //  Function to Reverse Linklist
    ListNode* reverse_ll(ListNode* node){
        
        ListNode* prev = node;
        ListNode* current = node->next;
        ListNode* next = node->next->next;
        
        ListNode* res = new ListNode(node->val);
        
        while(next){
            //  Reverse the chain
            // current->next = prev;
            ListNode* temp = new ListNode(current->val);
            temp->next = res;
            res = temp;
            //  shift pointers to next position
            prev = current;
            current = next;
            next = next->next;
        }
        ListNode* temp = new ListNode(current->val);
        temp->next = res;
        res = temp;
        
        return res;
    }
    
    bool isPalindrome(ListNode* head) {
        //  Base Case
        if(head == nullptr || head->next == nullptr)    return true;
        if(head->next->next == nullptr)                 return head->val == head->next->val ? true : false;
        
        //  From here list size is >= 3
        
        //  Reverse the linked list
        ListNode* r_head = reverse_ll(head);
        
        //  Compare corrosponding palindrome elements
        while(r_head && head){
            //  Palindrome condition failed
            if(head->val != r_head->val)
                return false;
            //  Move to next pointers
            r_head = r_head->next;
            head = head->next;
        }
        //  Successfull Palindrome
        return true;
    }
};