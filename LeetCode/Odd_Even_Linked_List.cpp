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
//      Time Compleixty  : O(N)
//      Space Complexity : O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //  No nodes in input
        if(head == nullptr) return head;
        
        //  Make sure initialize them with nullptr  OR  gargabe value fills is found
        ListNode* odd = nullptr;
        ListNode* o_head = nullptr;
        ListNode* even = nullptr;
        ListNode* e_head = nullptr;
        
        //  Maintain index odd check flag
        bool odd_flag = true;
        
        while(head){
            if(odd_flag){
                //  Odd
                if(o_head == nullptr){
                    o_head = head;
                    odd = o_head;
                }else{
                    odd->next = head;
                    odd = odd->next;
                }
            }
            else{
                //  Even
                if(e_head == nullptr){
                    e_head = head;
                    even = e_head;
                }else{
                    even->next = head;
                    even = even->next;
                }
            }
            //  Move to next node
            head = head->next;
            //  Update index flag
            odd_flag = !odd_flag;
        }
        //  If both even and odd indices are present    ie : more than 1 nodes
        if(o_head && e_head){
            odd->next = e_head;
            even->next = nullptr;
            return o_head;
        }
        //  Only one node in input
        return o_head == nullptr ? e_head : o_head;
        
    }
};