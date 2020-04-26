// another solution with fewer space complexity
// but still very slow

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
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* copyHead = new Node(head->val);
        Node* lastCpNode = copyHead;
        Node* curr = head->next;
        unordered_map<Node*, Node*> oldMapCopy;
        oldMapCopy[head] = copyHead;
        while(curr) {
            Node* copyNode = new Node(curr->val);
            lastCpNode->next = copyNode;
            oldMapCopy[curr] = copyNode;
            lastCpNode = lastCpNode->next;
            curr = curr->next;
        }
        
        Node* copyNode = copyHead;
        curr = head;
        while (curr) {
            copyNode->random = oldMapCopy[curr->random];
            copyNode = copyNode->next;
            curr = curr->next;
        }
        
        return copyHead;
    }
};
