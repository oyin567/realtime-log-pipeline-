#include <iostream>
#include <unordered_map>
#include <mutex>
#include <string>

class MetricsTracker {
private:
    std::unordered_map<std::string, int> metrics;
    mutable std::mutex mtx;

public:
    void increment(const std::string& metric) {
        std::lock_guard<std::mutex> lock(mtx);
        metrics[metric]++;
    }

    int get(const std::string& metric) const {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = metrics.find(metric);
        return (it != metrics.end()) ? it->second : 0;
    }
};

int main() {
    MetricsTracker tracker;
    tracker.increment("requests_total");
    tracker.increment("requests_total");
    tracker.increment("errors_500");

    std::cout << "Total Requests: " << tracker.get("requests_total") << "\n";
    std::cout << "Total Errors: " << tracker.get("errors_500") << "\n";
    return 0;
}
