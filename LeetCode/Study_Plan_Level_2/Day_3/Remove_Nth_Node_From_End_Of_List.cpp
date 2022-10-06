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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //  Base Case
        if(!head)
            return nullptr;
        //  Find length of the LL
        int length = 1;
        ListNode *temp = head;
        while(temp->next){
            temp = temp->next;
            length++;
        }
        //  Find nth node to be removed from the begining
        n = length - n;
        //  First node was to be removed
        if(n == 0)
            return head->next;
        length = 1;
        temp = head;
        //  Reach the node before the nth node
        while(temp->next && length < n){
            length++;
            temp = temp->next;
        }
        //  Remove the link
        temp->next = temp->next->next;
        //  Return head
        return head;
    }
};