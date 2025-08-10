class LRUCache {
private:
    // Node for doubly linked list
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // Helper function to remove a node
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Helper function to insert a node at the front
    void insertAtFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    // Constructor to initialize the cache with a given capacity
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0); // dummy head
        tail = new Node(0, 0); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    // Get the value of the key if it exists, otherwise return -1
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        }
        
        Node* node = cache[key];
        // Move this node to the front (most recently used)
        removeNode(node);
        insertAtFront(node);
        
        return node->value;
    }

    // Put a key-value pair into the cache
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists, update the value and move it to the front
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            insertAtFront(node);
        } else {
            // Key doesn't exist, create a new node
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insertAtFront(newNode);

            // If the cache exceeds the capacity, remove the least recently used node
            if (cache.size() > capacity) {
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */