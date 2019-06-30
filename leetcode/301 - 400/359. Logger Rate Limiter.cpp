#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Logger {
    unordered_map<string, int> messages;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (messages.find(message) != messages.end() && timestamp - messages[message] < 10)
            return false;
        messages[message] = timestamp;
        return true;
    }
};

int main(void) {
    return 0;
}
