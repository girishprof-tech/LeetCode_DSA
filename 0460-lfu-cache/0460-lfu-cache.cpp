struct Node {
    int key, val, cnt;
    Node* next;
    Node* prev;

    Node(int k, int v) {
        key = k;
        val = v;
        cnt = 1;
        next = prev = nullptr;
    }
};

struct DLL {
    Node* front;
    Node* back;

    DLL() {
        front = back = nullptr;
    }

    void add(Node* newNode) {
        if (!front) {
            front = back = newNode;
            return;
        }

        front->next = newNode;
        newNode->prev = front;
        front = newNode;
    }

    void remove(Node* root) {
        if (!back) return;

        if (back == front) {
            back = front = nullptr;
            root->next = root->prev = nullptr;
            return;
        }

        if (root == back) back = back->next;
        if (root == front) front = front->prev;

        if (root->next) root->next->prev = root->prev;
        if (root->prev) root->prev->next = root->next;

        root->next = root->prev = nullptr;
    }

    Node* removeLast() {
        if (!back) return nullptr;

        Node* temp = back;

        if (front == back) {
            front = back = nullptr;
        }
        else {
            back = back->next;
            back->prev = nullptr;
        }

        temp->next = temp->prev = nullptr;
        return temp;
    }
};

class LFUCache {
    int cap;
    int minFreq = 0;

    unordered_map<int, Node*> mpp;
    unordered_map<int, DLL> freq;

public:
    LFUCache(int capacity) {
        cap = capacity;
        mpp.reserve(capacity);
    }
    
    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;

        Node* curr = mpp[key];
        int oldFreq = curr->cnt;
        freq[oldFreq].remove(curr);

        curr->cnt++;
        freq[curr->cnt].add(curr);

        if (oldFreq == minFreq && freq[oldFreq].front == nullptr) {
            freq.erase(oldFreq);
            minFreq++;
        }

        return curr->val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;

        if (mpp.find(key) != mpp.end()) {
            Node* curr = mpp[key];
            int oldFreq = curr->cnt;
            freq[oldFreq].remove(curr);

            curr->cnt++;
            freq[curr->cnt].add(curr);

            if (oldFreq == minFreq && freq[oldFreq].front == nullptr) {
                freq.erase(oldFreq);
                minFreq++;
            }

            curr->val = value;
        }
        else {
            Node* newNode = new Node(key, value);

            if (mpp.size() == cap) {
                int f = minFreq;
                Node* temp = freq[f].removeLast();

                if (temp) {
                    mpp.erase(temp->key);
                    delete temp;
                }

                if (freq[f].front == nullptr) {
                    freq.erase(f);
                }
            }

            minFreq = 1;
            mpp[key] = newNode;
            freq[1].add(newNode);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */