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

uint32_t mod(uint32_t dividend, uint32_t divisor)
{
    return dividend % divisor;
}

uint32_t quick_mod(uint32_t dividend)
{
    return ((uint64_t)(dividend * magic) >> 32);
}

int main() {
    srand(time(NULL));

    uint32_t divisor = rand() % 30 + 2;
    time_t start = clock();
    for (int count = 0; count < 100000000; count++) {
        uint32_t dividend = rand();
        dividend = mod(dividend, divisor);
    }
    printf("after %f\n", (float) (clock() - start) / CLOCKS_PER_SEC);

    // divisor = rand() % 30 + 2;
    start = clock();
    div_init(divisor);
    for (int count = 0; count < 100000000; count++) {
        uint32_t dividend = rand();
        dividend = quick_mod(dividend);
    }
    printf("after quickmod: %f\n", (float) (clock() - start) / CLOCKS_PER_SEC);

    return 0;
}
