#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        pair<int, int> left(A.front(), A.back()), right(1, 1);
        while (left != right) {
            pair<int, int> mid(left.first + right.first, left.second + right.second),
                           small_than_mid(0, 1), large_than_mid(1, 1);
            int j = 1, count = 0;
            for (int i = 0; i < A.size(); i++) {
                while (j < A.size() && A[i] * mid.second > A[j] * mid.first)
                    j++;
                count += A.size() - j;
                if (j < A.size() && A[i] * small_than_mid.second > A[j] * small_than_mid.first) {
                    small_than_mid.first = A[i];
                    small_than_mid.second = A[j];
                }
                if (A[i] * large_than_mid.second < A[j - 1] * large_than_mid.first) {
                    large_than_mid.first = A[i];
                    large_than_mid.second = A[j - 1];
                }
            }
            if (count < K)
                left = large_than_mid;
            else
                right = small_than_mid;
        }
        return {left.first, left.second};
    }
};

class Solution_Heap_LTE {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        auto cmp = [&A](const pair<int, int>& a, const pair<int, int>& b) {
            auto diff = A[a.first] * A[b.second] - A[b.first] * A[a.second];
            if (diff > 0)
                return true;
            if (diff < 0)
                return false;
            return a > b;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        heap.emplace(0, A.size() - 1);
        while (--K) {
            auto top = heap.top();
            while (!heap.empty() && heap.top() == top) {
                heap.pop();
            }
            auto i = top.first, j = top.second;
            if (i + 1 < j && A[i + 1] != A[j])
                heap.emplace(i + 1, j);
            if (i < j - 1 && A[j - 1] != A[i])
                heap.emplace(i, j - 1);
        }
        return {A[heap.top().first], A[heap.top().second]};
    }
};

int main(void) {
    return 0;
}
