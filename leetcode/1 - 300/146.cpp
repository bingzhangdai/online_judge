#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class LRUCache{
    struct List_Node {
        int val;
        bool isvalid;
        List_Node *next, *prev;
        List_Node(int x) : val(x), isvalid(true), next(nullptr), prev(nullptr) {}
    };
    unordered_map<int, List_Node *> hash_map;
    List_Node *head, *tail;
    int capacity, size;
    
    bool is_in_list(int key) {
        auto pos = hash_map.find(key);
        if (pos != hash_map.end())
            return pos->second->isvalid;
        return false;
    }

    void insert_head(List_Node *node) {
        node->next = head->next;
        if (head->next)
            head->next->prev = node;
        head->next = node;
        node->prev = head;
        node->isvalid = true;
        size++;
        if (tail == head)
            tail = node;
    }

    void remove(List_Node *node) {
        node->prev->next = node->next;
        if (node->next)
            node->next->prev = node->prev;
        node->isvalid = false;
        size--;
        if (tail == node)
            tail = tail->prev;
    }

public:
    int get(int key) {
        if (is_in_list(key)) {
            auto node = hash_map[key];
            remove(node);
            insert_head(node);
            return node->val;
        }
        return -1;
    }
    
    void set(int key, int value) {
        auto pos = hash_map.find(key);
        if (is_in_list(key)) {
            pos->second->val = value;
            remove(pos->second);
        }
        else {
            if (size >= capacity)
                remove(tail);
            if (pos != hash_map.end())
                pos->second->val = value;
            else
                hash_map[key] = new List_Node(value);
        }
        insert_head(hash_map[key]);
    }

    ~LRUCache() {
        for_each(hash_map.begin(), hash_map.end(), [](pair<int, List_Node *> node_pair) {
                    delete node_pair.second; });
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        tail = head = new List_Node(-1);
    }
};

int main(void) {
    auto lru = LRUCache(2);
    lru.set(2, 2);
    lru.set(1, 1);
    lru.set(2, 2);
    lru.set(4, 4);
    cout << lru.get(1) << endl;
    lru.set(5, 5);
    return 0;
}

/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set. 
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 
*/
