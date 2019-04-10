#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.empty() || k == 0)
            return {};
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (x < arr[mid])
                right = mid;
            else if (x > arr[mid])
                left = mid + 1;
            else {
                left = right = mid;
            }
        }
        if (arr[left] > x && left > 0 && abs(x - arr[left - 1]) < abs(arr[left] - x))
            left = right = left - 1;
        if (arr[right] < x && right + 1 < arr.size() && abs(x - arr[right]) > abs(arr[right + 1] - x))
            left = right = right + 1;
        while (left > 0 && arr[left - 1] == arr[right]) {
            left--;
        }
        while (right + 1 < arr.size() && arr[right + 1] == arr[left]) {
            right++;
        }
        while (right - left + 1 < k) {
            int left_diff = INT_MAX, right_diff = INT_MAX;
            if (left > 0)
                left_diff = abs(x - arr[left - 1]);
            if (right + 1 < arr.size())
                right_diff = abs(arr[right + 1] - x);
            if (right_diff < left_diff) {
                ++right;
            } else {
                --left;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

int main(void) {
    return 0;
}
