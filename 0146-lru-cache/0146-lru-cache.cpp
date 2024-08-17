class Node {
    public:
        Node(int val, int key): val(val),key(key),next(nullptr),prev(nullptr){}
        int val;
        int key;
        Node* next;
        Node* prev;
};

class LRUCache {
public:
    int c = 0;
    unordered_map<int, Node*> um;
    Node* head = nullptr;
    Node* tail = nullptr;
    LRUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if (um.find(key) != um.end()){
            Node* x = um[key];
            if (x != head && x == tail){
                tail = tail->prev;
                tail->next = nullptr;
                x->prev = nullptr;
                x->next = head;
                head->prev = x;
                head = x;
            } else if (x != head) {
                x->prev->next = x->next;
                x->next->prev = x->prev;
                x->next = head;
                head->prev = x;
                head = x;
            }
            return x->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (um.find(key) == um.end()){
            if (!head){
                head = new Node(value, key);
                um[key] = head;
                tail = head;
            } else {
                Node* k = new Node(value, key);
                um[key] = k;
                k->next = head;
                head->prev = k;
                head = k;
                if (um.size() > c){
                    Node* k = tail;
                    int key2 = k->key;
                    tail = tail->prev;
                    delete k;
                    um.erase(key2);
                }
            }
        } else {
            Node* x = um[key];
            if (x != head && x == tail){
                tail = tail->prev;
                tail->next = nullptr;
                x->prev = nullptr;
                x->next = head;
                head->prev = x;
                x->val = value;
                head = x;
            } else if (x != head) {
                x->prev->next = x->next;
                x->next->prev = x->prev;
                x->val = value;
                x->next = head;
                head->prev = x;
                head = x;
            } else {
                x->val = value;
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