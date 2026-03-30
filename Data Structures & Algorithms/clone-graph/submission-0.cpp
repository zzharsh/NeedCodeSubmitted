/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> visited;
    Node* visit(Node* node)
    {
        if(visited.find(node->val) == visited.end())
        {
            visited[node->val] = new Node(node->val);
        }
        return visited[node->val];
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        queue<Node*> Q1, Q2;
        Q1.push(node);
        unordered_set<int> lV;
        Node* res = visit(node);
        while(!Q1.empty())
        {
            Node* temp = Q1.front();
            Node* newTemp = visit(temp);
            vector<Node*> newNeighbors;
            if(lV.find(temp->val) == lV.end())
            {
                for(int i = 0; i < temp->neighbors.size(); ++i)
                {
                    newNeighbors.push_back(visit(temp->neighbors[i]));
                    Q1.push(temp->neighbors[i]);
                }
                newTemp->neighbors = newNeighbors;
                lV.insert(temp->val);
            }
            Q1.pop();
        }
        return res;

        
    }
};
