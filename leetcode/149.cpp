#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
    void increment(unordered_map<double, int>& hash_map, double key) {
        if (hash_map.find(key) == hash_map.end())
            hash_map[key] = 1;
        else
            hash_map[key]++;
    }
    int maxVal(const unordered_map<double, int>& hash_map) {
        int max_val = 0;
        for (const auto& pair : hash_map)
            if (pair.second > max_val)
                max_val = pair.second;
        return max_val;
    }
public:
    int maxPoints(vector<Point>& points) {
        int max_points = 0;
        unordered_map<double, int> k_num;
        for (const auto& p : points) {
            k_num.clear();
            int same_points = 0;
            for (const auto& q : points) {
                if (q.x == p.x) {
                    if (q.y == p.y)
                        same_points++;
                    else
                        increment(k_num, INT_MAX);
                }
                else
                    increment(k_num, (double)(q.y-p.y) / (q.x-p.x));
            }
            max_points = max(max_points, maxVal(k_num) + same_points);
        }
        return max_points;
    }
};

int main(void) {
    return 0;
}
