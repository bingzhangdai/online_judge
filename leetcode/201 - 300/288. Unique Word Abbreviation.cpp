#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> hash_map;
    string to_abbr(const string& word) {
        if (word.length() < 2)
            return word;
        else
            return word.front() + to_string(word.length() - 2) + word.back();
    }
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (const auto& word : dictionary) {
            hash_map[to_abbr(word)].insert(word);
        }
    }

    bool isUnique(string word) {
        auto abbr = to_abbr(word);
        return hash_map.find(abbr) == hash_map.end() || hash_map[abbr].size() == 1 && *hash_map[abbr].begin() == word;
    }
};

int main(void) {
    return 0;
}
