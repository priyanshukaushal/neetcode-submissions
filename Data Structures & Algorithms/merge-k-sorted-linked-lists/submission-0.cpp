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
    ListNode * merge(ListNode * a, ListNode * b) {
        if(a == NULL) return b;
        if(b == NULL) return a;
        ListNode * curr = new ListNode();
        ListNode * head = curr;
        while(a != NULL && b != NULL) {
            if(a->val < b->val) {
                curr->next = a;
                a = a->next;
                curr = curr->next;
            } else {
                curr->next = b;
                b = b->next;
                curr = curr->next;
            }
        }
        if(a != NULL) curr->next = a;
        if(b != NULL) curr->next = b;
        return head->next;
    }

    ListNode * helper(vector<ListNode*>& lists, int i, int j) {
        if(i > j) return NULL;
        if(i==j) return lists[i];
        int mid = i+(j-i)/2;
        ListNode * a = helper(lists,i,mid);
        ListNode * b = helper(lists,mid+1,j);
        return merge(a,b);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(lists,0,lists.size()-1);
    }
};
