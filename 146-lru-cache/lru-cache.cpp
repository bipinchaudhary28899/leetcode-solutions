class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };
    
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;


    // Remove a node from the DLL
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node right after head (MRU position)
    void insertAtFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // move node to front (most recently used)
        remove(node);
        insertAtFront(node);

        return node->value;
    }

    void put(int key, int value) {
        // if key already exists
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;

            remove(node);
            insertAtFront(node);
            return;
        }

        // if cache is full
        if(mp.size() == capacity) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            remove(lru);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        insertAtFront(newNode);
        mp[key] = newNode;
    }
};
