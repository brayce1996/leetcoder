// Runtime: 24 ms, faster than 5.95% of C++ online submissions for Copy List with Random Pointer.
// Memory Usage: 11.2 MB, less than 100.00% of C++ online submissions for Copy List with Random Pointer.

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
        Node* curr = head;
        vector<Node*> copyList;
        unordered_map<Node*, int> addrToIndex;
        int index = 0;
        while (curr) {
            Node* copyCurr = new Node(curr->val);
            copyList.push_back(copyCurr);
            addrToIndex[curr] = index;
            index++;
            curr = curr->next;
        }
        copyList.push_back(NULL);
        curr = head;
        for (int i = 0; i < copyList.size() - 1; i++, curr = curr->next) {
            copyList[i]->next = copyList[i+1];
            if (curr->random) {
                copyList[i]->random = copyList[addrToIndex[curr->random]];
            }
        }
        return copyList[0];
    }
};
