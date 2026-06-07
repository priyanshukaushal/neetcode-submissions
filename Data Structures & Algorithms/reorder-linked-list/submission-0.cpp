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
    void reorderList(ListNode* head) {
        unordered_map<int,ListNode*> map;
        int count = 0;
        ListNode * curr = head;
        while(curr != NULL) {
            map[count] = curr;
            curr = curr->next;
            count++;
        }
        int n = map.size();
        ListNode * temp = new ListNode();
        ListNode * newHead = temp;
        int j = n-1;
        int i = 0;
        while(i<j) {
            temp->next = map[i];
            temp->next->next = map[j];
            i++;
            j--;
            temp = temp->next->next;
        }
        if(i==j) {
            temp->next = map[i];
            temp = temp->next;
        }
        temp->next = NULL;
        head = newHead->next;
    }
};
