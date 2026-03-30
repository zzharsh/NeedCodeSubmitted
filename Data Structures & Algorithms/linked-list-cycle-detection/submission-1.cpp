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
        ListNode* slow = head, *fast = head;
        if(head==nullptr || slow->next==nullptr || slow->next->next == nullptr)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
        while(slow!=fast)
        {
            if(slow->next == nullptr)
            {
                return false;
            }
            if(fast->next == nullptr)
            {
                return false;
            }
            if(fast->next->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
