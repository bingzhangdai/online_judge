#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>
using namespace std;

// This is the Master's API interface.
// You should not implement it, or speculate about its implementation
class Master {
  public:
    int guess(string word);
};

class Solution {
    const int len = 6;

    int dist(const string& s, const string& t) {
        int res = 0;
        for (int i = 0; i < len; i++)
            res += (s[i] == t[i]);
        return res;
    }

    int max_equidistant_set_count(const string& word, const list<string>& words) {
        vector<int> equidistant_set(len + 1, 0);
        for (const auto& w : words)
            equidistant_set[dist(w, word)]++;
        return *max_element(equidistant_set.begin(), equidistant_set.end());
    }

    list<string>::iterator get_candidate(list<string>& words) {
        auto candidate = words.begin();
        auto count = words.size();
        for (auto it = words.begin(); it != words.end(); ++it) {
            auto c = max_equidistant_set_count(*it, words);
            if (c < count)
                count = c, candidate = it;
        }
        return candidate;
    }

public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        list<string> words(wordlist.begin(), wordlist.end());
        while (!words.empty()) {
            auto it = get_candidate(words);
            auto word = *it;
            words.erase(it);
            auto match = master.guess(word);

            for (auto it = words.begin(); it != words.end();) {
                if (dist(word, *it) != match)
                    it = words.erase(it);
                else
                    ++it;
            }
        }
    }
};

class Solution_BAD {
    const int len = 6;

    int dist(const string& s, const string& t) {
        int res = 0;
        for (int i = 0; i < len; i++)
            res += (s[i] == t[i]);
        return res;
    }

public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        list<string> words(wordlist.begin(), wordlist.end());
        while (!words.empty()) {
            auto word = words.front();
            auto match = master.guess(word);
            words.erase(words.begin());
            for (auto it = words.begin(); it != words.end();) {
                if (dist(word, *it) != match)
                    it = words.erase(it);
                else
                    ++it;
            }
        }
    }
};

int main(void) {
    return 0;
}
