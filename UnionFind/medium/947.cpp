class Node {
public:
    int id;
    Node* root;
    int height;
    
    Node(int id) {
        this->id = id;
        this->root = this;
        this->height = 0;
    }
};

class UnionFind {
public:
    unordered_map<int, Node*> nodes;
    int islandCount = 0;
    UnionFind() {}
    
    Node* getNode(int id) {
        if (nodes.find(id) == nodes.end()) {
            nodes[id] = new Node(id);
            
            // discovered a new island
            islandCount++;
        }
        return nodes[id];
    }
    
    // return root of given node
    Node* find (Node* node) {
        if (node->root != node) {
            node->root = find(node->root);
        }
        return node->root;
    }
    
    // union two node, return the root of the two node
    Node* doUnion(Node* x, Node* y) {
        Node* xRoot = find(x);
        Node* yRoot = find(y);
        
        if (xRoot != yRoot) {
            // unionned two islands
            islandCount--;

            if (xRoot->height > yRoot->height) {
                yRoot->root = xRoot;
                return xRoot;
            } else if (xRoot->height < yRoot->height) {
                xRoot->root = yRoot;
                return yRoot;
            } else {
                yRoot->root = xRoot;
                xRoot->height++;
                return xRoot;
            }
        }
        return xRoot;
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf;
        for (auto stone: stones) {
            uf.doUnion(uf.getNode(stone[0]), uf.getNode(~stone[1]));
        }
        return stones.size() - uf.islandCount;
    }
};
