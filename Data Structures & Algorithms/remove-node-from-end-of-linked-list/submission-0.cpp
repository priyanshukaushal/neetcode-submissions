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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL && n == 1) return NULL;
        ListNode * s, * f;
        s = f = head;
        while(n > 0) {
            f = f->next;
            n--;
        }
        if(f == NULL) return head->next;
        while(f->next != NULL) {
            s = s->next;
            f = f->next;
        }
        s->next = s->next->next;
        return head;
    }
};
