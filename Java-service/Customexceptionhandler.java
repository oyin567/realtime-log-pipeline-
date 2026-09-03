class RateLimitExceededException extends Exception {
    public RateLimitExceededException(String message) {
        super(message);
    }
}

public class RateLimiter {
    private static final int MAX_REQUESTS_PER_SEC = 100;

    public void validateRate(int currentRps) throws RateLimitExceededException {
        if (currentRps > MAX_REQUESTS_PER_SEC) {
            throw new RateLimitExceededException("Ingestion limit breached: " + currentRps + " req/sec");
        }
    }

    public static void main(String[] args) {
        RateLimiter limiter = new RateLimiter();
        try {
            limiter.validateRate(120);
        } catch (RateLimitExceededException e) {
            System.err.println("Rejected: " + e.getMessage());
        }
    }
}
