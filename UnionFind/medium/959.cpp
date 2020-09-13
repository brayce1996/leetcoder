class Node {
public:
    Node* root;
    int height;
    
    Node() {
        this->root = this;
        this->height = 0;
    }
};

class UnionFind {
public:
    vector<vector<Node*>> table; // 2D table
    int regionCount = 0;
    
    UnionFind(int tableSize) {
        table = vector<vector<Node*>>(tableSize+1, vector<Node*>(tableSize+1, NULL));
        
        // union all edges
        for (int row = 0; row < table.size() - 1; row++) {
            this->doUnion(this->getNode(row, 0), this->getNode(row + 1, 0));
            this->doUnion(this->getNode(row, table.size() - 1),
                          this->getNode(row + 1, table.size() - 1));
        }
                          
        for (int col = 0; col < table.size() - 1; col++) {
            this->doUnion(this->getNode(0, col), this->getNode(0, col + 1));
            this->doUnion(this->getNode(table.size() - 1, col),
                          this->getNode(table.size() - 1, col + 1));
        }
    }
    
    Node* getNode(int row, int col) {
        if (table[row][col] == NULL) {
            table[row][col] = new Node();
        }
        return table[row][col];
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
        
        if (xRoot == yRoot) {
            regionCount++;
        }
        if (xRoot != yRoot) {
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
    int regionsBySlashes(vector<string>& grid) {
        UnionFind uf = UnionFind(grid.size());
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] != ' ') {
                    // don't think of slice
                    // think of nodes and lines, a slice is two nodes connected together
                    
                    // init two nodes for case '\'
                    int x1 = col;
                    int y1 = row;
                    int x2 = col + 1;
                    int y2 = row + 1;
                    if (grid[row][col] == '/') {
                        swap(x1, x2);
                    }
                    
                    uf.doUnion(uf.getNode(y1, x1), uf.getNode(y2, x2));
                }
            }
        }
        
        return uf.regionCount;
    }
};
