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

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* lr1, ListNode* lr2) {
       ListNode* ans = new ListNode();
       ListNode* curr = ans;
       int carry = 0;
       while(lr1 || lr2 || carry){
        int value;
        if(lr1 && lr2){
            value = (lr1->val + lr2->val + carry)%10;
            carry = (lr1->val + lr2->val + carry)/10;
            lr1=lr1->next;
            lr2=lr2->next;
        }
        else if(lr1 && !lr2){
            value = (lr1->val + carry)%10;
            carry = (lr1->val + carry)/10;
            lr1=lr1->next;
        }
        else if(!lr1 && lr2){
            value = (lr2->val + carry)%10;
            carry = (lr2->val + carry)/10;
            lr2=lr2->next;
        }else if(carry){
            value = carry;
            carry = (carry)/10;
        }
        curr->next = new ListNode(value);
        curr = curr->next;
       }
       return ans->next;
    }
};
