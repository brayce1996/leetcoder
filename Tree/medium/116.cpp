// Runtime: 32 ms, faster than 14.72% of C++ online submissions for Populating Next Right Pointers in Each Node.
// Memory Usage: 17.2 MB, less than 100.00% of C++ online submissions for Populating Next Right Pointers in Each Node.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root) q.push(root);
        int levelLimit = 1;
        int currLevelCount = 0;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            currLevelCount++;
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            
            if (currLevelCount == levelLimit) {
                levelLimit = levelLimit * 2;
                currLevelCount = 0;
            } else {
                curr->next = q.front();
            }
        }
        return root;
    }
};