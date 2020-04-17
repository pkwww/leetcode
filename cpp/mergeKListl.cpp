/**
 * Definition for singly-linked list.
 */
#include <vector>
using namespace std;
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
    
    void deleteList(ListNode* head) {
        ListNode** curr = &head;
        while (*curr != nullptr) {
            ListNode* entry = *curr;
            *curr = entry->next;
            delete entry;
        }
    }

    ListNode* recurse(vector<ListNode*>& lists, int begin, int end) {
        // exclusive end
        if (end - begin == 1) {
            // copy a list
            return mergeTwoLists(lists[begin], nullptr);
        }
        if (end - begin == 2) {
            return mergeTwoLists(lists[begin], lists[begin+1]);
        }
        
        int mid = (begin + end) / 2;
        ListNode* merged1 = recurse(lists, begin, mid);
        ListNode* merged2 = recurse(lists, mid, end);
        
        ListNode* merged_list = mergeTwoLists(merged1, merged2);
        deleteList(merged1);
        deleteList(merged2);
        
        return merged_list;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        return recurse(lists, 0, lists.size());
    }
};
