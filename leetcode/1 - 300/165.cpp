#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    int convert(string& version) {
        auto p = version.find('.');
        int res;
        if (p == string::npos) {
            res = version == "" ? 0 : stoi(version);
            version = "";
        }
        else {
            res = stoi(version.substr(0, p));
            version = version.substr(p + 1);
        }
        return res;
    }
public:
    int compareVersion(string version1, string version2) {
        int ver1 = convert(version1), ver2 = convert(version2);
        return ver1 > ver2 ? 1 : ver1 < ver2 ? -1 : version1 == version2 ? 0 : compareVersion(version1, version2);
    }
};

int main(void) {
    return 0;
}
