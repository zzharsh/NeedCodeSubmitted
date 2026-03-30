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
        ListNode* temp1 = list1, *temp2 = list2;
        ListNode* current, *headReturn;
        if(temp1 == nullptr && temp2 == nullptr)
        {
            return temp1;
        }
        if(temp1!=nullptr && temp2!=nullptr)
        { 
            if(temp1->val < temp2->val)
            {
                current = temp1;
                headReturn = current;
                temp1 = temp1->next;

            }
            else
            {
                current = temp2;
                headReturn = current;
                temp2 = temp2->next;
            }
        }
        else if (temp1!=nullptr)
        {
            return temp1;
        }
        else
        {
            return temp2;
        }
        while((temp1!=nullptr) && (temp2!=nullptr))
        {
            //  = temp1->val < temp2->val ? temp1 : temp2;
            // cout<<temp1->val<<" "<<temp2->val<<"\n";
            if(temp1->val < temp2->val)
            {
                current->next = temp1;
                temp1 = temp1->next; 
            }
            else
            {
                current->next = temp2;
                temp2 = temp2->next;
            }
            current = current->next;
        }
        if(temp1!=nullptr)
        {
            current->next = temp1;
            // cout<<temp1->val<<"\n";
            // current->next = temp1;
            // temp1 = temp1->next;
        }
        if(temp2!=nullptr)
        {
            // cout<<temp2->val<<"\n";
            current->next = temp2;
            // temp2 = temp2->next;
        }
        return headReturn;
    }
};
