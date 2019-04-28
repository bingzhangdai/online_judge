#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class FileSystem {
    vector<string> split(const string path, char c) {
        vector<string> res;
        int pos = 0;
        while (pos < path.length()) {
            int next = path.find(c, pos);
            if (next == -1)
                next = path.length();
            res.push_back(path.substr(pos, next - pos));
            pos = next + 1;
        }
        return res;
    }

    struct Node {
        string content = "";
        map<string, Node *> children;
    };

    Node *root = new Node();

    Node *find(string path) {
        auto paths = split(path, '/');
        auto curr = root;
        for (int i = 1; i < paths.size(); i++) {
            if (!curr->children[paths[i]])
                curr->children[paths[i]] = new Node();
            curr = curr->children[paths[i]];
        }
        return curr;
    }

public:
    FileSystem() {}
    // You can assume all file or directory paths are absolute paths which begin with / and do not end with / except that the path is just "/".
    // You can assume that all operations will be passed valid parameters and users will not attempt to retrieve file content or list a directory or file that does not exist.
    vector<string> ls(string path) {
        auto curr = find(path);
        vector<string> res;
        for (const auto p : curr->children)
            res.push_back(p.first);
        if (curr->content != "") {
            res.push_back(split(path, '/').back());
        }
        return res;
    }

    void mkdir(string path) {
        find(path);
    }

    void addContentToFile(string filePath, string content) {
        auto curr = find(filePath);
        curr->content += content;
    }

    string readContentFromFile(string filePath) {
        auto curr = find(filePath);
        return curr->content;
    }
};

int main(void) {
    return 0;
}
