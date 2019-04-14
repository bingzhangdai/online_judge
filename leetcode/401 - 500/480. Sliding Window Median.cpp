#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
    class Median {
        multiset<int> left;
        multiset<int> right;
        double median = 0;

        double cal() {
            if (left.size() == right.size())
                return ((double)*left.rbegin() + *right.begin()) / 2;
            return *right.begin();
        }

        void balance() {
            if (right.size() > left.size() + 1) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            if (left.size() > right.size()) {
                right.insert(*left.rbegin());
                left.erase(--left.end());
            }
        }

    public:
        double get() {
            return median;
        }

        void insert(int num) {
            if (num >= median)
                right.insert(num);
            else
                left.insert(num);
            balance();
            median = cal();
        }

        void remove(int num) {
            if (num >= median)
                right.erase(right.find(num));
            else
                left.erase(left.find(num));
            balance();
            median = cal();
        }
    };

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        auto median = Median();
        for (int i = 0; i < k; i++) {
            median.insert(nums[i]);
        }
        vector<double> res{median.get()};
        for (int i = k; i < nums.size(); i++) {
            median.insert(nums[i]);
            median.remove(nums[i - k]);
            res.push_back(median.get());
        }
        return res;
    }
};

int main(void) {
    return 0;
}
