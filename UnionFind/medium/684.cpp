class Node {
public:
    int val;
    Node* root;
    int height;
    
    Node(int val) {
        this->val = val;
        this->root = this;
        this->height = 0;
    }
};

class UnionFind {
public:
    vector<Node*> nodes;
    UnionFind(int nodeCount) {
        
        for (int i = 0; i < nodeCount; i++) {
            nodes.push_back(new Node(i));
        }
    }
    
    // return root of given node
    Node* find (int id) {
        if (nodes[id]->root != nodes[id]) {
            nodes[id]->root = find(nodes[id]->root->val);
        }
        return nodes[id]->root;
    }
    
    // union two node, return whether the union is successful
    bool doUnion(int x, int y) {
        Node* xRoot = find(x);
        Node* yRoot = find(y);
        
        if (xRoot != yRoot) {
            if (xRoot->height > yRoot->height) {
                yRoot->root = xRoot;
            } else if (xRoot->height < yRoot->height) {
                xRoot->root = yRoot;
            } else {
                yRoot->root = xRoot;
                xRoot->height++;
            }
            return true;
        }
        return false;
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind *uf = new UnionFind(edges.size() + 1);
        
        for (auto edge: edges) {
            if (!uf->doUnion(edge[0], edge[1])) {
                return edge;
            }
        }
        
        return vector<int>(2, -1);
    }
};
