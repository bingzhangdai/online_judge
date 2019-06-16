#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    const int max_int = 100000;
    vector<int> disjoint_set = vector<int>(max_int + 1, 0);
    unordered_map<int, int> size;
    vector<int> primes;
    unordered_set<int> primes_back;
    int find_parent(int x) {
        int p = x;
        while (disjoint_set[p] != 0)
            p = disjoint_set[p];
        // path compression
        while (x != p) {
            auto tmp = disjoint_set[x];
            disjoint_set[x] = p;
            x = tmp;
        }
        return p;
    }
    int join(int x, int y) {
        if (x != y) {
            size[x] += size[y];
            disjoint_set[y] = x;
        }
        return x;
    }
    vector<int> factors(int x) {
        vector<int> res;
        for (auto i : primes) {
            if (primes_back.find(x) != primes_back.end()) {
                res.push_back(x);
                break;
            }
            if (x % i == 0) {
                res.push_back(i);
            }
            while (x % i == 0)
                x /= i;
            if (x == 1)
                break;
        }
        return res;
    }
public:
    Solution() {
        vector<bool> is_prime = vector<bool>(max_int + 1, true);
        for (int i = 2; i <= max_int; i++) {
            if (!is_prime[i])
                continue;
            primes.push_back(i);
            primes_back.insert(i);
            for (auto j = 2; j * i <= max_int; j++)
                is_prime[j * i] = false;
        }
    }
    int largestComponentSize(vector<int> & A) {
        for (auto num : A) {
            auto f = factors(num);
            if (f.empty())
                continue;
            auto x = find_parent(f.front());
            size[x]++;
            for (auto i = 1; i < f.size(); i++)
                x = join(x, find_parent(f[i]));
        }
        auto res = 1;
        for (auto it = size.begin(); it != size.end(); ++it)
            if (it->second > res)
                res = it->second;
        return res;
    }
};

int main(void) {
    return 0;
}
