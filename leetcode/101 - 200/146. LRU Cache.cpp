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

class LRUCache_2 {
    template <class TKey, class TVal>
    class linkedlist_map {
        struct Node {
            TKey key;
            TVal val;
            bool valid = true;
            Node* next = nullptr;
            Node* prev = nullptr;
            Node(TKey key, TVal val) : key(key), val(val) {}
        };

        unordered_map<TKey, Node *> hash_map;
        Node *head = nullptr, *tail = nullptr;
    public:
        int size = 0;

        TVal operator[](const TKey& key) {
            auto pos = hash_map.find(key);
            if (pos != hash_map.end())
                return pos->second->valid ? pos->second->val : TVal();
            return TVal();
        }

        bool find(TKey key) {
            auto pos = hash_map.find(key);
            return pos != hash_map.end() ? pos->second->valid : false;
        }

        void remove(TKey key) {
            auto node = hash_map[key];
            if (node->prev)
                node->prev->next = node->next;
            else
                head = node->next;
            if (node->next)
                node->next->prev = node->prev;
            else
                tail = node->prev;
            node->valid = false;
            size--;
        }

        void set(const TKey& key, const TVal& val) {
            Node* node;
            auto pos = hash_map.find(key);
            if (pos != hash_map.end()) {
                node = pos->second;
                if (node->valid)
                    remove(node->key);
                node->val = val, node->valid = true, node->prev = node->next = nullptr;
            }
            else
                node = hash_map[key] = new Node(key, val);
            if (!head)
                head = tail = node;
            else
                node->next = head, head->prev = node, head = node;
            size++;
        }

        // remove the last key
        void pop() {
            if (tail)
                remove(tail->key);
        }

        ~linkedlist_map() {
            for_each(hash_map.begin(), hash_map.end(), [](pair<TKey, Node *> node_pair) {
                delete node_pair.second;
            });
        }
    };

    int capacity;
    linkedlist_map<int, int> list_map;
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (list_map.find(key)) {
            auto val = list_map[key];
            list_map.set(key, val);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        list_map.set(key, value);
        if (list_map.size > capacity)
            list_map.pop();
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
