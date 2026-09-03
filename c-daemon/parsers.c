#include <stdio.h>
#include <string.h>

typedef struct {
    char ip[16];
    int status;
    char method[8];
    char route[64];
} LogEntry;

int parse_log(const char *input, LogEntry *out) {
    if (input == NULL || out == NULL) return -1;
    
    int items_parsed = sscanf(input, "%15s %d %7s %63s", 
                              out->ip, 
                              &out->status, 
                              out->method, 
                              out->route);
    
    return (items_parsed == 4) ? 0 : -1;
}

int main() {
    LogEntry log;
    const char *raw_input = "192.168.1.1 200 GET /index.html";
    
    if (parse_log(raw_input, &log) == 0) {
        printf("Success:\nIP: %s\nStatus: %d\nMethod: %s\nRoute: %s\n", 
               log.ip, log.status, log.method, log.route);
    } else {
        printf("Failed to parse log string.\n");
    }
    return 0;
}
