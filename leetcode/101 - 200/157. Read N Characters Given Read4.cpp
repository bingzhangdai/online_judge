#include <cstring>
#include <vector>
using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char* buf, int n) {
        int n_read = 0;
        while (n_read < n) {
            if (n - n_read < 4) {
                char tmp[4];
                int res = min(read4(tmp), n - n_read);
                memcpy(buf + n_read, tmp, res);
                n_read += res;
                break;
            }
            int res = read4(buf + n_read);
            n_read += res;
            if (res < 4)
                break;
        }
        return n_read;
    }
};

int main(void) {
    return 0;
}