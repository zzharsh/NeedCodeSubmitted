/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> CopiedNodes;
    Node* makeCopy(Node* temp)
    {
        if(temp->next == nullptr)
        {
            Node* newNode = new Node(temp->val);
            newNode->next = nullptr;
            // newNode->val = temp->val;
            CopiedNodes[temp] = newNode;
            return newNode;
        }
        else
        {
            Node* newNode = new Node(temp->val);
            // newNode->val = temp->val;
            CopiedNodes[temp] = newNode;
            newNode->next = makeCopy(temp->next);
            return newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        
        Node* temp = head;
        if(temp==nullptr)
        {
            return temp;
        }
        Node* newNode = makeCopy(temp);
        Node* newTemp = newNode;
        temp = head;
        while (temp!=nullptr)
        {
            if(temp->random!=nullptr)
            {
                newTemp->random = CopiedNodes[temp->random];
            }
            temp = temp->next;
            newTemp = newTemp->next;
        }
        return newNode;
    }
};
