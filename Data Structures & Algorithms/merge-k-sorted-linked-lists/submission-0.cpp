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
    ListNode* findMin(vector<ListNode*>& lists)
    {
        int mn = INT_MAX;
        ListNode* ans = nullptr;
        int imin = 0;
        for(int i = 0; i < lists.size(); ++i)
        {
            ListNode* llist = lists[i];
            if(llist != nullptr && mn > llist->val)
            {
                mn = llist->val;
                ans = llist;
                imin = i;
            }
        }
        if (ans != nullptr) lists[imin] = lists[imin]->next;
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* head = findMin(lists);
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            temp->next = findMin(lists);
            temp = temp->next;
        }
        return head;
    }
};
