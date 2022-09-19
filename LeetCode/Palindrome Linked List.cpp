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
//      Space Complexity : O(N)
class Solution {
public:
    //  Solution Approach without reversing the linked list
    bool isPalindrome(ListNode* head) {
        //  Get the length of the linked list
        int len = 0;
        ListNode *temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        //  Recursive function to solve the problem
        function<bool(int)> solve = [&](int cur_index)->bool{
            //  Check if reached the middle element
            if(cur_index == (len+1)/2){
                //  For Even Length
                if(len%2 == 0){
                    bool res = head->val == head->next->val;
                    head = head->next->next;
                    return res;
                }
                //  For Odd length
                head = head->next;
                return true;
            }
            //  Save the value of the current node : HEAD CALL
            int c_val = head->val;
            head = head->next;
            //  Continue solving till middle of the linked list
            if(solve(cur_index+1) == false)
                return false;
            //  Check the saved value with current node value(Palindromic Value) : TAIL CALL
            if(c_val != head->val)
                return false;
            //  Move to next value
            head = head->next;
            return true;
        };
        
        return solve(1);
        // return false;
        
    }
};