#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* create_log_message(const char* prefix, const char* message) {
    if (!prefix || !message) return NULL;

    // Calculate total required length: '[' + prefix + '] ' + message + '\0'
    size_t length = strlen(prefix) + strlen(message) + 4;
    char* log_str = (char*)malloc(length * sizeof(char));
    
    if (log_str == NULL) return NULL;

    snprintf(log_str, length, "[%s] %s", prefix, message);
    return log_str;
}

int main() {
    char* formatted = create_log_message("ERROR", "Database connection timeout");
    if (formatted) {
        printf("%s\n", formatted);
        free(formatted); // Prevent memory leak
    }
    return 0;
}
