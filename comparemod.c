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
    FILE *mod_file = fopen("mod.txt", "w");

    time_t start = clock(), end;
    for (int count = 0; count < 1000; count++) {
        uint32_t dividend = rand();
        start = clock();
        for (int i = 0; i < 1000; i++)
            dividend = mod(dividend, count + 2);
        end = clock();
        fprintf(mod_file, "%f\n", (double) (end - start) / CLOCKS_PER_SEC);
        printf("ans: %d\n", dividend);
    }
    fclose(mod_file);

    FILE *quick = fopen("quick_mod.txt", "w");

    for (int count = 0; count < 1000; count++) {
        uint32_t dividend = rand();
        start = clock();
        for (int i = 0; i < 1000; i++) {
            div_init(count + 2);
            dividend = quick_mod(dividend);
        }
        end = clock();
        fprintf(quick, "%f\n", (double) (end - start) / CLOCKS_PER_SEC);
        printf("ans: %d\n", dividend);
    }

    return 0;
}
