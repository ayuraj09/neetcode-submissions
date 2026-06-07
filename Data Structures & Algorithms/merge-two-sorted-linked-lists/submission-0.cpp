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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        // curr = head;

        while(list1 && list2){
            if(list1->val<=list2->val){
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
                curr->next = nullptr;
            }
            else if(list1->val>list2->val){
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
                curr->next = nullptr;
            }
        }

        if(!list1 && list2) curr->next = list2;
        if(list1 && !list2) curr->next = list1;

        // if(list1->val <=list2->val){
        //     head = list1
        // }else head = list2;
        return head->next;
       
    }
};
