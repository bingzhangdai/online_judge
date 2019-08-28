#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> hash_map;
public:
    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        hash_map[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& values = hash_map[key];
        auto it = upper_bound(values.begin(), values.end(), pair<int, string>{timestamp, ""});
        if (it != values.end() && it->first == timestamp)
            return it->second;
        if (it != values.begin())
            return prev(it)->second;
        return "";
    }
};

int main(void) {
    return 0;
}
