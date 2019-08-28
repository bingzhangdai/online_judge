#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class PhoneDirectory {
    int maxNumbers;
    unordered_set<int> available;
    int count = 0;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers): maxNumbers(maxNumbers) {
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (available.empty()) {
            if (count == maxNumbers)
                return -1;
            return count++;
        }
        auto res = *available.cbegin();
        available.erase(available.cbegin());
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (available.count(number))
            return true;
        if (count == maxNumbers)
            return false;
        if (number < 0 || number >= count)
            return true;
        return false;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number >= 0 && number < count)
            available.insert(number);
    }
};

int main(void) {
    return 0;
}
