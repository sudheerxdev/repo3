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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to make the result list easier to handle
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;
        
        // Traverse both linked lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;  // Start with carry from previous iteration
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Update carry for next iteration
            carry = sum / 10;
            
            // Create a new node with the digit value of sum % 10
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        
        return dummyHead->next;  // Return the result list (skipping dummyHead)
    }
};
