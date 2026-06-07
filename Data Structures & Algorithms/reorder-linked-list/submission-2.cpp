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
    ListNode * findMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode * s, * f;
        s = f = head;
        ListNode * prev = head;
        while(f != NULL && f->next != NULL) {
            prev = s;
            s = s->next;
            f = f->next->next;
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
        ListNode * mid = findMiddle(head);
        ListNode * rev = reverse(mid);
        ListNode * a = head;
        ListNode * b = rev;
        ListNode * newHead = new ListNode();
        ListNode * curr = newHead;
        while(a != NULL && b != NULL) {
            ListNode * anext = a->next;
            ListNode * bnext = b->next;
            a->next = NULL;
            b->next = NULL;
            curr->next = a;
            curr->next->next = b;
            curr = curr->next->next;
            a = anext;
            b = bnext;
        }
        if(a != NULL) curr->next = a;
        if(b != NULL) curr->next = b;
        head = newHead->next;
    }
};
