#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
*/

class Solution {
    unordered_map<int, int> dir_len;
public:
    int lengthLongestPath(string input) {
        int pos = 0, res = 0;
        while (pos < input.length()) {
            bool isFile = false;
            int len = 0, j = pos, count = 0;
            while (j < input.length() && input[j] != '\n') {
                if (input[j] == '\t')
                    count++;
                else {
                    if (input[j] == '.')
                        isFile = true;
                    len++;
                }
                j++;
            }
            if (isFile) {
                int curr_res = len + count;
                for (int i = 0; i < count; i++) {
                    curr_res += dir_len[i];
                }
                res = max(res, curr_res);
            } else
                dir_len[count] = len;
            pos = j + 1;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
