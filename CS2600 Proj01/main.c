#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt.h"
#define BUF_SZ 4096U
#define FILE_SZ 20
int main() 
{
	FILE* src;
	FILE* dst;
	FILE* enc;
	char encryptee[FILE_SZ];
	char encrypter[FILE_SZ];
	char encrypted[FILE_SZ];
	
	printf("Please enter source file Name: ");
	scanf("%s", &encryptee);

	if((src = fopen(encryptee, "rb")) == 0)
	{
		printf("Could not open source file\n");
		exit(-1);
	}
	printf("Please enter one-time-pad file Name: ");
	scanf("%s", &encrypter);
	if((enc = fopen(encrypter, "rb")) == 0)
	{	
		printf("Could not open OTP file\n");
		fclose(src);
		exit(-1);
	}
	printf("Please enter destination file Name: ");
	scanf("%s", &encrypted);

	dst = (fopen(encrypted, "wb"));
	printf("Finished opening\n");

	encryption(src, enc, dst);
	printf("Finished encryption\n");	

	fclose(src);
	fclose(dst);
	fclose(enc);
}
