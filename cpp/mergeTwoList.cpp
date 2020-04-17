
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead = new ListNode(0);
        ListNode* curr = dummyhead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2-> val) {
                curr->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                curr->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            curr = curr->next;
        }
        while (l1 != nullptr) {
            curr->next = new ListNode(l1->val);
            l1 = l1->next;
            curr = curr->next;
        }
        while (l2 != nullptr) {
            curr->next = new ListNode(l2->val);
            l2 = l2->next;
            curr = curr->next;
        }

        ListNode* realhead = dummyhead->next;
        delete dummyhead;
        return realhead;
    }
};
