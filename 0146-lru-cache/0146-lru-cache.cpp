class Node {
public: 
    int data; 
    int val;
    Node* next;
    Node* prev;

    Node(int d, int v) {
        data = d;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mpp;
    int cap;
    int size;

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;

        Node* temp = mpp[key];

        if (tail == temp) {
            return temp->val;
        }

        if (head == temp) {
            head = head->next;
        }

        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;

        tail->next = temp;
        temp->prev = tail;
        tail = tail->next;
        temp->next = nullptr;

        return temp->val;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];

            if (tail == temp) {
                mpp[key]->val = value;
                return;
            }

            if (head == temp) {
                head = head->next;
            }
            
            if (temp->next) temp->next->prev = temp->prev;
            if (temp->prev) temp->prev->next = temp->next;

            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
            temp->next = nullptr;

            mpp[key]->val = value;
        }
        else if (head == nullptr) {
            Node* newNode = new Node(key, value);
            tail = newNode;
            head = newNode;
            size = 1;
            mpp[key] = tail;
        }
        else if (size == cap) {
            int data = head->data;
            mpp.erase(data);
            head->data = key;
            head->val = value;
            mpp[key] = head;

            if (head != tail) {
                Node* temp = head;
                head = head->next;

                if (temp->next) temp->next->prev = temp->prev;
                if (temp->prev) temp->prev->next = temp->next;

                tail->next = temp;
                temp->prev = tail;
                tail = tail->next;
                temp->next = nullptr;
            }
        }
        else {
            Node* newNode = new Node(key, value);

            tail->next = newNode;
            mpp[key] = newNode;
            newNode->prev = tail;
            tail = tail->next;
            size++;
        }    
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */