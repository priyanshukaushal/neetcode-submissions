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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * curr1 = list1;
        ListNode * curr2 = list2;
        ListNode * newHead = new ListNode();
        ListNode * newCurr = newHead;
        while(curr1 != nullptr && curr2 != nullptr) {
            if(curr1->val < curr2->val) {
                newCurr->next = curr1;
                newCurr = curr1;
                curr1 = curr1->next;
            } else {
                newCurr->next = curr2;
                newCurr = curr2;
                curr2 = curr2->next;
            }
        }
        if(curr1) newCurr->next = curr1;
        if(curr2) newCurr->next = curr2;
        return newHead->next;
    }
};
