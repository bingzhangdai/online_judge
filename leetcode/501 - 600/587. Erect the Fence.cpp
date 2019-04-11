#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
    bool isLeft(const Point& x, const Point& y, const Point& point) {
        return (y.x - x.x) * (point.y - y.y) - (y.y - x.y) * (point.x - y.x) >= 0;
    }

public:
    vector<Point> outerTrees(vector<Point>& points) {
        vector<Point> res;
        sort(points.begin(), points.end(), [](const Point& x, const Point& y) {
            return x.x < y.x || x.x == y.x && x.y < y.y;
        });

        res.push_back(points.front());
        for (int i = 1; i < points.size(); i++) {
            bool isAllLeft = true;
            for (int k = i + 1; k < points.size(); k++) {
                if (!isLeft(res.back(), points[i], points[k])) {
                    isAllLeft = false;
                    break;
                }
            }
            if (isAllLeft)
                res.push_back(points[i]);
        }

        res.push_back(points.back());
        for (int i = points.size() - 1; i >= 0; i--) {
            bool isAllLeft = true;
            for (int k = i - 1; k >= 0; k--) {
                if (!isLeft(res.back(), points[i], points[k])) {
                    isAllLeft = false;
                    break;
                }
            }
            if (isAllLeft)
                res.push_back(points[i]);
        }

        sort(res.begin(), res.end(), [](const Point& x, const Point& y) {
            return x.x < y.x || x.x == y.x && x.y < y.y;
        });

        res.erase(unique(res.begin(), res.end(), [](const Point& x, const Point& y) {
            return x.x == y.x && x.y == y.y;
        }), res.end());

        return res;
    }
};

// LTE
/*
class Solution {
    bool isLeft(const Point& x, const Point& y, const Point& point) {
        return (y.x - x.x) * (point.y - y.y) - (y.y - x.y) * (point.x - y.x) >= 0;
    }
public:
    vector<Point> outerTrees(vector<Point>& points) {
        vector<Point> res;
        if (points.size() <= 2)
            return points;  
        for (int i = 0; i < points.size(); i++) {
            bool isOuter = false;
            for (int j = 0; j < points.size(); j++) {
                if (j == i)
                    continue;
                bool isAllLeft = true;
                for (int k = 0; k < points.size(); k++) {
                    if (!isLeft(points[i], points[j], points[k])) {
                        isAllLeft = false;
                        break;
                    }
                }
                if (isAllLeft) {
                    isOuter = true;
                    break;
                }
            }
            if (isOuter)
                res.push_back(points[i]);
        }
        return res;
    }
};
*/

int main(void) {
    return 0;
}
