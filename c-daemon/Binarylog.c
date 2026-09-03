#include <stdio.h>

int verify_header(const unsigned char* bytes, size_t len) {
    if (!bytes || len < 4) return 0;

    const unsigned char magic[4] = {0x4C, 0x4F, 0x47, 0x53};
    for (int i = 0; i < 4; i++) {
        if (bytes[i] != magic[i]) return 0;
    }
    return 1;
}

int main() {
    unsigned char valid_stream[] = {0x4C, 0x4F, 0x47, 0x53, 0x01, 0x02};
    unsigned char invalid_stream[] = {0x00, 0x00, 0x47, 0x53};

    printf("Valid check: %d\n", verify_header(valid_stream, 6));
    printf("Invalid check: %d\n", verify_header(invalid_stream, 4));
    return 0;
}
