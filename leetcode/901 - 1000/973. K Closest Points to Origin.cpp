#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    static int dist(int x, int y) {
        return x * x + y * y;
    }

    static bool cmp(const vector<int>& l, const vector<int>& r) {
        return dist(l[0], l[1]) < dist(r[0], r[1]);
    }

    void pivot(vector<vector<int>>& points, int begin, int end) {
        auto mid = (begin + end) / 2;
        if (!cmp(points[begin], points[end - 1]))
            swap(points[begin], points[end - 1]);
        if (!cmp(points[mid], points[end - 1]))
            swap(points[mid], points[end - 1]);
        if (cmp(points[begin], points[mid]))
            swap(points[begin], points[mid]);
    }

    void kth_element(vector<vector<int>>& points, int begin, int end, int k) {
        if (end - begin <= 5) {
            return nth_element(points.begin() + begin, points.begin() + begin + k, points.begin() + end, cmp);
        }
        pivot(points, begin, end);
        auto p = points[begin];
        auto left = begin, right = end - 1;
        while (left <= right) {
            while (cmp(points[left], p))
                left++;
            while (cmp(p, points[right]))
                right--;
            if (left <= right)
                swap(points[left++], points[right--]);
        }
        if (left - begin == k)
            return;
        if (left - begin < k)
            kth_element(points, left, end, k - left + begin);
        else
            kth_element(points, begin, left, k);
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        kth_element(points, 0, points.size(), K);
        vector<vector<int>> res;
        res.insert(res.end(), points.begin(), points.begin() + K);
        return res;
    }
};

int main(void) {
    return 0;
}
