import java.util.List;
import java.util.concurrent.CompletableFuture;
import java.util.stream.Collectors;

public class BatchLogProcessor {

    public static CompletableFuture<List<String>> processBatchAsync(List<String> rawLogs) {
        return CompletableFuture.supplyAsync(() -> 
            rawLogs.stream()
                   .map(log -> "[PROCESSED] " + log.toUpperCase())
                   .collect(Collectors.toList())
        );
    }

    public static void main(String[] args) throws Exception {
        List<String> logs = List.of("db connection lost", "timeout on port 8080", "unauthorized access attempt");
        
        CompletableFuture<List<String>> future = processBatchAsync(logs);
        
        // Non-blocking processing callback
        future.thenAccept(processed -> processed.forEach(System::println)).get();
    }
}
