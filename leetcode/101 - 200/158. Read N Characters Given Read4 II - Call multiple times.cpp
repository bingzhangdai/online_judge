#include <cstring>
#include <vector>
using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    char tmp[4];
    int size = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char* buf, int n) {
        int n_read = 0;
        while (n_read < n) {
            if (size) {
                int n_copy = min(size, n - n_read);
                memcpy(buf + n_read, tmp, n_copy);
                n_read += n_copy;
                if (n_copy < size) {
                    // memcpy(tmp, tmp + n_copy, size - n_copy);
                    // memmove(tmp, tmp + n_copy, size - n_copy);
                    for (auto i = 0; i < size - n_copy; i++)
                        *(tmp + i) = *(tmp + n_copy + i);
                }
                size -= n_copy;
            }
            if (!size)
                size = read4(tmp);
            if (!size)
                break;
        }
        return n_read;
    }
};

int main(void) {
    return 0;
}