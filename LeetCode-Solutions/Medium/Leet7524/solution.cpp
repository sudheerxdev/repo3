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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)return NULL;
        ListNode * curr = head ; 
        ListNode * pre = NULL; 
//ListNode * post = curr->next;
        while(curr != NULL){
            ListNode * post = curr->next;
           curr->next = pre;
         //  pre = pre -> next;
          pre = curr ; 
          curr = post;
        }
        return pre;
    }
};
