#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    vector<unordered_set<int>> sums{ {0} };
    const double eps = 0.001;

    bool findtarget(const vector<int>& A, int target, int size) {
        if (sums.size() <= size) {
            sums.resize(size + 1);
            for (const auto num : A)
                for (auto i = size; i >= 1; i--)
                    for (const auto sum : sums[i - 1])
                        sums[i].insert(sum + num);
        }

        return sums[size].find(target) != sums[size].end();
    }
public:
    bool splitArraySameAverage(vector<int>& A) {
        double avg = 1.0 * accumulate(A.begin(), A.end(), 0) / A.size();
        for (auto size = A.size() / 2; size > 0; size--) {
            auto sum = size * avg;
            int round = sum + eps;
            if (abs(sum - round) > eps)
                continue;
            if (findtarget(A, round, size))
                return true;
        }
        return false;
    }
};

class Solution_LTE {
    const double eps = 0.001;
    bool dfs(const vector<int>& A, int target, int depth, int pos) {
        if (depth == 0)
            return target == 0;
        if (pos == A.size() || target < 0)
            return false;
        for (int i = pos; i < A.size(); i++) {
            if (dfs(A, target - A[i], depth - 1, i + 1))
                return true;
        }
        return false;
    }
public:
    bool splitArraySameAverage(vector<int>& A) {
        double avg = 1.0 * accumulate(A.begin(), A.end(), 0) / A.size();
        for (auto size = 1; size <= A.size() / 2; size++) {
            auto sum = size * avg;
            int round = sum + eps;
            if (abs(sum - round) > eps)
                continue;
            if (dfs(A, round, size, 0))
                return true;
        }
        return false;
    }
};

int main(void) {
    return 0;
}
