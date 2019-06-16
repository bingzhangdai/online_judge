#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> hash_set;
        for (const auto& email : emails) {
            string local = "";
            int pos = -1;
            while (email[++pos] != '@') {
                if (email[pos] == '+')
                    break;
                if (email[pos] == '.')
                    continue;
                local += email[pos];
            }
            while (email[pos++] != '@');
            hash_set.insert(local + '@' + email.substr(pos, email.length() - pos));
        }
        return hash_set.size();
    }
};

int main(void) {
    return 0;
}
