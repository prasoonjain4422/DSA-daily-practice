
struct node {
    int value = -1;
};

struct pairNode {
    int key;
    int value;
    pairNode* next = NULL;
    pairNode* prev = NULL;
};


class LRUCache {
    
    int cacheCapacity;
    int currCapacity = 0;
    unordered_map<int, pairNode*> addr;
    pairNode *head = new pairNode(), *tail = new pairNode();
    
public:
    LRUCache(int capacity) {
        // constructor
        cacheCapacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(addr[key] == NULL)
        {
            return -1;
        }
        else
        {
            int ans = addr[key]->value;
            
            if(addr[key]->prev != NULL)
            {
                addr[key]->prev->next = addr[key]->next;            
            }
            
            if(addr[key]->next != NULL)
            {
                addr[key]->next->prev = addr[key]->prev;
            }
            
            addr[key]->prev = head;
            addr[key]->next = head->next;
            head->next->prev = addr[key];
            head->next = addr[key];
            
            return ans;
        }
    }
    
    void put(int key, int value) {
        
        if(addr[key] == NULL)
        {
            if(currCapacity >= cacheCapacity)
            {
                currCapacity--;
                pairNode* temp = tail->prev;
                
                if(tail->prev != NULL)
                {
                    tail->prev = tail->prev->prev;
                    tail->prev->next = tail;
                    addr[temp->key] = NULL;
                }
                // delete temp;
            }
            
            addr[key] = new pairNode();
            addr[key]->value = value;
            addr[key]->key = key;

            addr[key]->next = head->next;
            addr[key]->next->prev = addr[key];
            addr[key]->prev = head;
            head->next = addr[key];
            currCapacity++;

        }
        else
        {
            addr[key]->value = value;
            get(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */