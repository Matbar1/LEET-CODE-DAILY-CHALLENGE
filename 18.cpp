    class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
    };

    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int capacity;
    int size;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            update(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            update(node);
        } else {
            Node* newNode = new Node();
            newNode->key = key;
            newNode->value = value;
            cache[key] = newNode;
            add(newNode);
            size++;
            if (size > capacity) {
                Node* tailPrev = tail->prev;
                remove(tailPrev);
                cache.erase(tailPrev->key);
                delete tailPrev;
                size--;
            }
        }
    }

private:
    void update(Node* node) {
        remove(node);
        add(node);
    }

    void add(Node* node) {
        Node* headNext = head->next;
        head->next = node;
        node->prev = head;
        node->next = headNext;
        headNext->prev = node;
    }

    void remove(Node* node) {
        Node* nodePrev = node->prev;
        Node* nodeNext = node->next;
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
    }
};

