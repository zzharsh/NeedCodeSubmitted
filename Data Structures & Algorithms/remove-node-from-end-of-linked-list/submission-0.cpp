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
        int sz = 0;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            temp = temp->next;
            sz++;
        }
        int k = sz-n;
        temp = head;
        if( k == 0)
        {
            temp =  head->next;
            delete head;
            return temp;
        }
        for(int i = 0; i < k-1; ++i)
        {
            temp=temp->next;
        }
        ListNode *del = temp->next;
        temp->next= temp->next->next;
        delete del;
        return head;
    }
};
