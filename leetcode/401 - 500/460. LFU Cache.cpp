#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class LFUCache {
    int min_freq = 0;
    unordered_map<int, int> key_val;
    unordered_map<int, int> key_freq;
    unordered_map<int, deque<int>> freq_key;
    int capacity;
    void updateFreq(int key) {
        auto& keys = freq_key[key_freq[key]];
        // NOT O(1)
        keys.erase(find(keys.begin(), keys.end(), key));
        if (min_freq == key_freq[key] && keys.empty())
            min_freq++;
        key_freq[key]++;
        freq_key[key_freq[key]].push_front(key);
    }
public:
    LFUCache(int capacity): capacity(capacity) { }

    int get(int key) {
        if (key_val.find(key) == key_val.end())
            return -1;
        auto& keys = freq_key[key_freq[key]];
        updateFreq(key);
        return key_val[key];
    }

    void put(int key, int value) {
        if (key_val.find(key) != key_val.end()) {
            key_val[key] = value;
            updateFreq(key);
        }
        else if (key_val.size() < capacity) {
            key_val[key] = value;
            min_freq = ++key_freq[key];
            freq_key[key_freq[key]].push_front(key);
        }
        else {
            if (capacity == 0)
                return;
            auto to_erase = freq_key[min_freq].back();
            freq_key[min_freq].pop_back();
            key_freq.erase(to_erase);
            key_val.erase(to_erase);
            put(key, value);
        }
    }
};

int main(void) {
    return 0;
}
