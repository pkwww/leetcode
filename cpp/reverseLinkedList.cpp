/**
 * Definition for singly-linked list.
 * };
 */
struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(nullptr) {}
};
#include <vector>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* rev_head = nullptr;
        ListNode* curr = head;
        for (; curr != nullptr; ) {
            ListNode* next = curr->next;
            curr->next = rev_head;
            rev_head = curr;
            curr = next;
        }
        return rev_head;
    }
};
