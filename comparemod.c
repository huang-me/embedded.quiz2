#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

uint32_t magic;

void div_init(uint32_t d) {
    uint64_t two_to_k = ((uint64_t) 1<<32);
    magic = (uint32_t)(two_to_k / d);
    return;
}

int main() {
    time_t start = time(NULL);
    srand(time(NULL));
    for (int count = 0; count < 10000000; count++) {
        uint32_t divisor = rand() % 30 + 2;
        uint32_t divident = rand();
        divident %= divisor;
    }
    printf("after %f\n", (float) (time(NULL) - start) / 3600);
    start = time(NULL);

    for (int count = 0; count < 10000000; count++) {
        uint32_t divisor = rand() % 30 + 2;
        uint32_t divident = rand();
        divident = ((uint64_t)(divident * magic)) >> 32;
    }
    printf("after quickmod: %f\n", (float) (time(NULL) - start) / 3600);

    return 0;
}
