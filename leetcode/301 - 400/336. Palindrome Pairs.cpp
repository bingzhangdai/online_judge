#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Example 1:
Input: ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]] 
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:
Input: ["bat","tab","cat"]
Output: [[0,1],[1,0]] 
Explanation: The palindromes are ["battab","tabbat"]
*/

class Solution {
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j && s[i] == s[j]) {
            j--;
            i++;
        }
        return i >= j;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> hash_map;
        for (int i = 0; i < words.size(); i++) {
            hash_map[words[i]] = i;
        }
        auto cmp = [](const string& s1, const string& s2) { return s1.length() > s2.length(); };
        sort(words.begin(), words.end(), cmp);
        vector<vector<int>> res;
        for (auto& s : words) {
            int curr_index = hash_map[s];
            hash_map.erase(s);
            reverse(s.begin(), s.end());
            if (hash_map.find(s) != hash_map.end()) {
                res.push_back({ hash_map[s], curr_index });
                res.push_back({ curr_index, hash_map[s] });
            }
            for (int i = 0; i < s.length(); i++) {
                if (!isPalindrome(s, 0, i))
                    continue;
                auto it = hash_map.find(s.substr(i + 1, s.length() - i - 1));
                if (it != hash_map.end())
                    res.push_back({ curr_index, it->second });
            }
            for (int i = s.length() - 1; i >= 0; i--) {
                if (!isPalindrome(s, i, s.length() - 1))
                    continue;
                auto it = hash_map.find(s.substr(0, i));
                if (it != hash_map.end())
                    res.push_back({ it->second, curr_index });
            }
        }
        return res;
    }
};

int main(void) {
    return 0;
}
