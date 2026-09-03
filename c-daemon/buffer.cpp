#include <iostream>
#include <vector>
#include <mutex>

class LogBuffer {
private:
    std::vector<std::string> buffer;
    size_t capacity;
    size_t head = 0;
    size_t tail = 0;
    bool full = false;
    std::mutex mtx;

public:
    explicit LogBuffer(size_t size) : capacity(size), buffer(size) {}

    void push(const std::string& log) {
        std::lock_guard<std::mutex> lock(mtx);
        buffer[head] = log;
        if (full) {
            tail = (tail + 1) % capacity;
        }
        head = (head + 1) % capacity;
        full = head == tail;
    }

    void display() {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Current Buffer Content Status (Head: " << head << "):" << std::endl;
        for (const auto& item : buffer) {
            if (!item.empty()) std::cout << " [ " << item << " ] ";
        }
        std::cout << std::endl;
    }
};

int main() {
    LogBuffer logQueue(3);
    logQueue.push("LOG_001: 200 OK");
    logQueue.push("LOG_002: 404 NOT FOUND");
    logQueue.push("LOG_003: 500 SERVER ERROR");
    logQueue.push("LOG_004: 200 OK"); // Overwrites oldest entry

    logQueue.display();
    return 0;
}
