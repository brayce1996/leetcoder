class Node {
public:
    Node* next;
    Node* prev;
    int val;

    Node(int val, Node* prev = NULL, Node* next = NULL) {
        this->val = val;
        this->prev = prev;
        this->next = next;

        if (this->prev) this->prev->next = this;
        if (this->next) this->next->prev = this;
    }

    void eraseSelf() {
        if (this->prev) this->prev->next = this->next;
        if (this->next) this->next->prev = this->prev;
        this->prev = NULL;
        this->next = NULL;
    }
};

class FirstUnique {
public:
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
    FirstUnique(vector<int>& nums) {
        head = new Node(-1);
        tail = head;

        for (int num: nums) {
            this->add(num);
        }
    }

    int showFirstUnique() {
        if (head->next) {
            return head->next->val;
        } else {
            return -1;
        }
    }

    void add(int value) {
        if (map.find(value) != map.end()) {
            if (map[value] == tail) {
                tail = map[value]->prev;
            }
            map[value]->eraseSelf();
        } else {
            map[value] = new Node(value, tail);
            tail = map[value];
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
