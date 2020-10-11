#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXSIZE 10000

uint64_t hexchar2val(char *in)
{
    int len = strlen(in), len_cpy = len - 1;
    uint32_t output = 0;
    while (--len >= 0) {
        uint8_t in_char = in[len];
        const uint8_t letter = in_char & 0x40;
        const uint8_t shift = (letter >> 3) | (letter >> 6);
        output |= ((in_char + shift) & 0xf) << (4 * (len_cpy - len));
    }
    return output;
}

int main()
{
    char input[MAXSIZE];
    unsigned long num = 0;

    if (scanf("%s", input)) {
        num = hexchar2val(input);
        printf("%lu\n", num);
    }
    return 0;
}
