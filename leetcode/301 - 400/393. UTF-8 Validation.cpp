#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
For 1-byte character, the first bit is a 0, followed by its unicode code.
For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
This is how the UTF-8 encoding would work:
   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int pos = 0;
        while (pos < data.size()) {
            if ((data[pos] & 0x80) == 0) {
                pos++;
                continue;
            }
            int num_ones = 0;
            for (int i = 0; i < 4; i++) {
                if ((data[pos] & 0x80 >> i) != 0)
                    num_ones++;
                else
                    break;
            }
            if (num_ones < 2)
                return false;
            if ((data[pos] & 0x80 >> num_ones) != 0)
                return false;
            if (pos + num_ones > data.size())
                return false;
            for (int i = 1; i < num_ones; i++) {
                if ((data[pos + i] & 0b11000000) != 0x80)
                    return false;
            }
            pos += num_ones;
        }
        return true;
    }
};

int main(void) {
    return 0;
}
