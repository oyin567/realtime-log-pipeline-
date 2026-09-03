#include <iostream>
#include <queue>
#include <string>

enum Severity { INFO = 1, WARNING = 2, CRITICAL = 3 };

struct LogPayload {
    Severity level;
    std::string message;

    // Overload comparison operator for priority queue ordering
    bool operator<(const LogPayload& other) const {
        return this->level < other.level;
    }
};

int main() {
    std::priority_queue<LogPayload> logQueue;

    logQueue.push({INFO, "User logged in"});
    logQueue.push({CRITICAL, "Database connection failure"});
    logQueue.push({WARNING, "Disk space low"});

    while (!logQueue.empty()) {
        LogPayload top = logQueue.top();
        std::cout << "Processing Priority [" << top.level << "]: " << top.message << "\n";
        logQueue.pop();
    }
    return 0;
}
