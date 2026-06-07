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
    ListNode * middle(ListNode* head) {
        ListNode * s, * f;
        s = f = head;
        ListNode * prev = head;
        while(f != NULL && f->next != NULL) {
            prev = s;
            s = s->next;
            f = f->next->next;
        }
        if(f != NULL) {
            prev = s;
            s = s->next;
        }
        prev->next = NULL;
        return s;
    }

    ListNode * reverse(ListNode * head) {
        ListNode * prev = NULL;
        while(head != NULL) {
            ListNode * next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode * mid = middle(head);
        ListNode * rev = reverse(mid);
        ListNode * curr = head;

        while(curr != NULL && rev != NULL) {
            ListNode * currNext = curr->next;
            curr->next = rev;
            rev = rev->next;
            curr->next->next = currNext;
            curr = currNext;
        }
    }
};
