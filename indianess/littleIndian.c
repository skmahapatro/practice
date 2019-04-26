#include<stdio.h>
void main()
{
	/* 
     * array is indianess independent
     * But each element in array is indaness dependent
     */
    int intArr[4]   = {12,34,56,78};
    char charArr[4] = {'A','B','C','D'};
    int intA        = 0x12345678;
    int i;
    char *ch;

    printf("Int Array address and value\n");
    ch = (char *)&intArr;
    for(i = 0; i<16; i++) {
        printf("Add - %x, value - %d\n", (unsigned int)(ch + i), *(ch+i));
    }

    printf("Char Array address and value\n");
    ch = (char *)&charArr;
    for(i = 0; i<4; i++) {
        printf("Add - %x, value - %d\n", (unsigned int)(ch + i), *(ch+i));
    }

    printf("Int address and value\n");
    ch = (char *)&intA;
    for(i = 0; i<4; i++)
        printf("Add - %x, value - %x\n", (unsigned int)(ch + i), *(ch + i));
}

