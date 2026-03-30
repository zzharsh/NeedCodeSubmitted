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
    ListNode* reverse(ListNode* head, int k)
    {
        ListNode* temp = head;
        ListNode* tempP = nullptr;
        int i = 0;
        while(i++ < k)
        {
            // if(temp == nullptr) return head;
            if(nullptr == temp) break;
            ListNode* tt = temp->next;
            cout<<temp->val<<endl;
            temp->next = tempP;
            tempP = temp;
            temp = tt;
        }
        // head -> next = afterTail;
        // tempP->next = afterTail;
        return tempP;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int n = 0;
        for(ListNode* temp = head; temp != nullptr; temp = temp->next)
        {
            n++;
        }
        if(n < 2 || k == 1) return head;
        ListNode* prev = nullptr, *nextt = nullptr, *tail = head;
        ListNode* result = head, *ptail = nullptr;
        ListNode* temp = head;
        // return reverse(head, k);
        for(int i = 0; i+k <= n; i += k)
        {
            for(int j = 1; j < k; ++j)
            {
                temp = temp->next;
                // if(temp != nullptr) cout<<temp->val<<endl;
                // cout<<j<<endl;
            }
            nextt = temp -> next;
            ListNode* rev = reverse(tail,k);
            if(result == head)
            {
                result = rev;
            }
            if(ptail != nullptr)
            {
                ptail->next = rev;
            }
            ptail = tail;
            tail = nextt;
            temp = nextt;
            cout<<ptail->val<<endl;
        }
        // if(temp != nullptr) cout<<temp->val<<endl;
        ptail->next = temp;
        // return head;
        return result;
        // return reverse(head, nullptr, head->next->next->next, k);
    }
};
