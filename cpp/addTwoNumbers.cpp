#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* previous = dummyHead;
        int carry = 0;
        ListNode* l1_curr = l1;
        ListNode* l2_curr = l2;
        
        while (l1_curr != NULL && l2_curr != NULL) {
            int sum = l1_curr->val + l2_curr->val + carry;
            carry = sum / 10;
            int value = sum % 10;
            previous->next = new ListNode(value);
            previous = previous->next;
            l1_curr = l1_curr->next;
            l2_curr = l2_curr->next;
        }
        
        while (l1_curr != NULL) {
            int sum = l1_curr->val + carry;
            carry = sum / 10;
            int value = sum % 10;
            previous->next = new ListNode(value);
            previous = previous->next;
            l1_curr = l1_curr->next;
        }
        
        while (l2_curr != NULL) {
            int sum = l2_curr->val + carry;
            carry = sum / 10;
            int value = sum % 10;
            previous->next = new ListNode(value);
            previous = previous->next;
            l2_curr = l2_curr->next;
        }
        
        if (carry != 0) {
            previous->next = new ListNode(carry);
            previous = previous->next;
        }
        
        ListNode* realHead = dummyHead->next;
        delete dummyHead;
        return realHead;
    }
};
