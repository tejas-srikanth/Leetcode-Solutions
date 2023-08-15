struct dll{
    public:
        int key, val;
        dll *prev, *next;
        dll(int k, int v){
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }

};


class LRUCache {
public:
    dll *beg, *end;
    unordered_map<int, dll*> um;
    int cap;

    LRUCache(int capacity) {
        beg = nullptr; end = nullptr;
        cap = capacity;
    }

    void removeAndInsert(dll* node){
        if (node == end){
            return;
        } else {
            if (node == beg){
                beg = beg->next;
            }
            end->next = node;

            dll* pr = node->prev;
            dll* ne = node->next;

            node->prev = end;
            end = node;
            node->next = nullptr;

            if (pr){
                pr->next = ne;
            }

            if (ne){
                ne->prev = pr;
            }
        }
    }

    void insert(dll* node){
        if (!end){
            beg = node;
            end = node;
        } else {
            end->next = node;

            dll* pr = node->prev;
            dll* ne = node->next;

            node->prev = end;
            end = node;
            end->next = nullptr;

            if (pr){
                pr->next = ne;
            }

            if (ne){
                ne->prev = pr;
            }
        }
    }

    void printList(){
        dll* n = beg;
        while (n){
        cout << n->key << " " << n->val << "-> ";
        n = n->next;
        }
        cout << endl;
    }
    
    int get(int key) {
        if (um.find(key) == um.end()){
            return -1;
        } else {
            removeAndInsert(um[key]);
            return um[key]->val;
        }
    }
    
    void put(int key, int value) {
        if (um.find(key) != um.end()){
            um[key]->val = value;
            removeAndInsert(um[key]);
        } else {
            if (um.size() == cap){
                dll* n = new dll(key, value);
                insert(n);
                dll* x = beg;
                beg = beg->next;
                beg->prev = nullptr;
                um.erase(x->key);
                um[key] = n;
            } else {
                dll* n = new dll(key, value);
                insert(n);
                um[key] = end;
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