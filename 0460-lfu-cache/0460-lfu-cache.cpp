struct Node {
    int key, val, cnt;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), val(v), cnt(1), next(nullptr), prev(nullptr) {}
};

struct DLL {
    Node* front = nullptr;
    Node* back = nullptr;

    void add(Node* newNode) {
        if (!front) {
            front = back = newNode;
            return;
        }

        front->next = newNode;
        newNode->prev = front;
        front = newNode;
    }

    void remove(Node* node) {
        if (node == front) front = node->prev;
        if (node == back) back = node->next;

        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;

        node->next = node->prev = nullptr;
    }

    Node* removeLast() {
        Node* temp = back;
        if (temp) remove(temp);
        return temp;
    }

    bool empty() const {
        return front == nullptr;
    }
};

class LFUCache {
    int cap, minFreq = 0;
    unordered_map<int, Node*> mpp;
    unordered_map<int, DLL> freq;

    void update(Node* root) {
        int oldFreq = root->cnt;
        auto it = freq.find(oldFreq);

        it->second.remove(root);
        if (it->second.empty()) {
            freq.erase(it);
            if (minFreq == oldFreq) minFreq++;
        }

        root->cnt++;
        freq[root->cnt].add(root);
    }

public:
    LFUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        auto it = mpp.find(key);

        if (it == mpp.end()) return -1;

        Node* curr = it->second;
        update(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;

        auto it = mpp.find(key);

        if (it != mpp.end()) {
            Node* curr = it->second;
            curr->val = value;
            update(curr);
            return;
        }

        if (mpp.size() == cap) {
            auto fit = freq.find(minFreq);
            Node* temp = fit->second.removeLast();

            mpp.erase(temp->key);
            delete temp;

            if (fit->second.empty()) {
                freq.erase(fit);
            }
        }

        Node* newNode = new Node(key, value);
        minFreq = 1;
        mpp[key] = newNode;
        freq[1].add(newNode);
    }

    ~LFUCache() {
        for (auto& entry : mpp) {
            delete entry.second;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */