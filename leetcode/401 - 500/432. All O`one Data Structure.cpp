#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class AllOne {
    unordered_map<string, Node *> key_val;
    struct Node {
        int val;
        Node(int val): val(val) {}
        unordered_set<string> keys;
        Node *prev = null_ptr;
        Node *next = null_ptr;
    };
    Node *left = null_ptr, right = null_ptr;
public:
    /** Initialize your data structure here. */
    AllOne() {
        left = right = new Node(0);
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto ptr = key_val[key];
        if (ptr != null_ptr) {
            ptr->key.erase(key);
        }
        else {
            ptr = left;
        }
        if (ptr->next == null_ptr) {
            right = ptr->next = new Node(ptr->val + 1);
            right->prev = ptr;
        }
        else if (left->next->val > ptr->val + 1) {
            auto tmp = ptr->next;
            ptr->next = new Node(ptr->val + 1);
            ptr->next->prev = ptr;
            ptr->next->next = tmp;
            tmp->prev = ptr->next;
        }
        key_val[key] = ptr->next;
        ptr->next->keys.insert(key);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto ptr = key_val[key];
        if (!ptr)
            return;
        ptr->keys.erase(key);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        
    }
};

int main(void) {
    return 0;
}
