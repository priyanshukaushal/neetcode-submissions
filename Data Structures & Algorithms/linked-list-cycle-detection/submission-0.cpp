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
    bool hasCycle(ListNode* head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode * s = head;
        ListNode * f = head->next->next;
        while(s != NULL && f != NULL) {
            if(s==f) return true;
            s = s->next;
            f = f->next ? f->next->next : NULL;
        }
        return false;
    }
};
