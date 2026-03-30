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
        ListNode* first = head, *second = nullptr, *temp = head;
        int n = 0;
        while(temp!=nullptr)
        {
            temp = temp->next;
            n++;
        }
        if(n<2) return;
        temp = head;
        ListNode *tt;
        for(int i = 0; i < n/2; ++i)
        {
            tt = temp;
            cout<<temp->val<<" "<<i<<" "<<n<<"\n";
            temp = temp->next;
        }
        second = temp;
        tt->next = nullptr;
        cout<<"tt "<<tt->val<<"\n";
        // temp->next = nullptr;
        // reverse
        {
            ListNode *pOld=nullptr, *pNew, *pTemp = second;
            while(pTemp!=nullptr)
            {
                pNew = pTemp->next;
                pTemp->next = pOld;
                pOld = pTemp;
                pTemp = pNew;              
            }
            second = pOld;
            // int i=0;
            // while(pTemp!=nullptr)
            // {
            //     // second = temp;
            //     cout<<pTemp->val<<" "<<i++<<"\n";
            //     pTemp = pTemp->next;
            // }
        }
        // interleave
        ListNode* pA = head, *pB = second, *last;
        while((pA!=nullptr) && (pB!=nullptr))
        {
            ListNode* pNA = pA->next;
            ListNode* pNB = pB->next;
            pA->next = pB;
            pB->next = pNA;
            last = pB;
            pA = pNA;
            pB = pNB;
        }
        if(pB!=nullptr)
            last->next = pB;
        // cout<<pA<<" "<<pB<<" "<<last;
    }
};
