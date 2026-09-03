import java.util.HashMap;
import java.util.Map;

public class LogAggregator {
    private final Map<Integer, Integer> statusCodeCounts = new HashMap<>();

    public void processStatusCode(int statusCode) {
        statusCodeCounts.put(statusCode, statusCodeCounts.getOrDefault(statusCode, 0) + 1);
    }

    public void printSummary() {
        System.out.println("Log Aggregation Summary:");
        statusCodeCounts.forEach((code, count) -> 
            System.out.println("HTTP " + code + ": " + count + " requests")
        );
    }

    public static void main(String[] args) {
        LogAggregator aggregator = new LogAggregator();
        aggregator.processStatusCode(200);
        aggregator.processStatusCode(200);
        aggregator.processStatusCode(404);
        aggregator.processStatusCode(500);

        aggregator.printSummary();
    }
}
