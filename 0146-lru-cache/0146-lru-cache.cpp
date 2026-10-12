class LRUCache {
    queue<pair<int, int>> q;
    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;  
    }
    
    int get(int key) {
        queue<pair<int, int>> temp;

        while (!q.empty() && q.front().first != key) {
            temp.push(q.front());
            q.pop();
        }

        int res;

        if (q.empty()) {
            res = -1;
        }
        else {
            res = q.front().second;
            q.push(q.front());
            q.pop();
        }

        while (!q.empty()) {
            temp.push(q.front());
            q.pop();
        }

        swap(q, temp);

        return res;
    }
    
    void put(int key, int value) {
        queue<pair<int, int>> temp;

        while (!q.empty() && q.front().first != key) {
            temp.push(q.front());
            q.pop();
        }

        if (q.empty()) {
            swap(q, temp);
            if (q.size() == cap) q.pop();
            q.push({key, value});
        }
        else {
            q.front().second = value;
            q.push(q.front());
            q.pop();

            while (!q.empty()) {
                temp.push(q.front());
                q.pop();
            }

            swap(q, temp);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */