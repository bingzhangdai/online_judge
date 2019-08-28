#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), i = 0, count = 0;
        while (count < n) {
            if (arr[i])
                i++, count++;
            else
                i++, count += 2;
        }
        if (count > n)
            arr[count = n - 1] = arr[--i];
        while (count) {
            if (!arr[i - 1])
                arr[--count] = arr[i - 1];
            arr[--count] = arr[--i];
        }
    }
};

int main(void) {
    return 0;
}
