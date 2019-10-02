#include <cstddef>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0;
        for (ListNode* node = headA; node != nullptr; node = node->next) {
            countA++;
        }
        int countB = 0;
        for (ListNode* node = headB; node != nullptr; node = node->next) {
            countB++;
        }
        
        
        if (countA <= countB) {
            for (int i = 0; i < countB - countA; headB = headB->next, i++);
        } else {
            for (int i = 0; i < countA - countB; headA = headA->next, i++);
        }
        for (; headA != nullptr && headB != nullptr; 
             headA = headA->next, headB = headB->next) {
            if (headA == headB)
                return headA;
        }
        return nullptr;
    }

#define MARK(ptr) do{((long)(*ptr) |= 1)}while(0)
#define VISITED(ptr) (reinterpret_cast<long>(ptr) & 1)
#define ADDR(ptr) reinterpret_cast<ListNode*>(reinterpret_cast<long>(ptr) & ~3)
    ListNode *getIntersectionNodeBitTrick(ListNode *headA, ListNode *headB) {
        for (ListNode* node = headA; node != nullptr; node = ADDR(node->next)) {
            long ptr_val = (long)node->next;
            node->next = reinterpret_cast<ListNode*>(ptr_val | 1);
        }
        ListNode* ret = nullptr;
        for (ListNode* node = headB; node != nullptr; node = ADDR(node->next)) {
            if (VISITED(node->next)) {
                ret = node;
                break;
            }
        }
        for (ListNode* node = headA; node != nullptr; node = ADDR(node->next)) {
            long ptr_val = (long)node->next;
            node->next = reinterpret_cast<ListNode*>(ptr_val & ~1);
        }
        return ret;
    }
};
