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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1 = l1, *t2 = l2;
        int carry=0;
        ListNode* sum = t1;
        while((t1!=nullptr) && (t2!=nullptr))
        {
            sum = t1;
            int s = t1->val + t2->val + carry;
            sum->val = s%10;
            carry = s/10;
            cout<<t1->val<<" "<<t2->val<<" "<<s<<"\n";
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t2!=nullptr)
        {
            int s = t2->val + carry;
            t2->val = s%10;
            carry = s/10;
            sum->next = t2;
            t2 = t2->next;
            sum = sum->next;
        }
        while(t1 != nullptr)
        {
            sum = t1;
            int s = t1->val + carry;
            t1->val = s%10;
            carry = s/10;
            t1 = t1->next;
        }
        if (carry > 0)
        {
            ListNode* newptr = new ListNode(carry);
            sum->next = newptr;
        }
        return l1;

    }
};
