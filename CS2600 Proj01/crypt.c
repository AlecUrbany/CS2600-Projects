#include <stdio.h>
#include <stdlib.h>
#include "crypt.h"
#define BUF_SZ 4096U
char bufferSRC[BUF_SZ];
char bufferOTP[BUF_SZ];
int qty;
int i;
void encryption(FILE* src, FILE* enc, FILE* dst)
{
    while (qty = fread(bufferSRC, sizeof(char), BUF_SZ, src))
    {
        fread(bufferOTP, sizeof(char), BUF_SZ, enc);

        for(int i = 0; i < qty; i++)
        {
            bufferSRC[i] ^= bufferOTP[i];
        }
        fwrite(bufferSRC, sizeof(char), qty, dst);
    }
}

