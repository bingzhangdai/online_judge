#include <iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
    unordered_map<RandomListNode *, RandomListNode *> hash_map;
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return nullptr;
        if (hash_map.find(head) == hash_map.end()) {
            hash_map[head] = new RandomListNode(head->label);
            hash_map[head]->next = copyRandomList(head->next);
            hash_map[head]->random = copyRandomList(head->random);
        }
        return hash_map[head];
    }
};

int main(void) {
    return 0;
}