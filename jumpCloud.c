#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(int c_count, int* c) {
    int i;
    int jumpNum = 0;

    int jumpingOnClouds(int c_count, int* c) {
        int i;
        int jumpNum = 0;

        for(i=0; i<c_count-1;jumpNum++)
            i+=(c[i+2] == 0)?2:1;
        return jumpNum;
    }

int main()
{
    int c[] = {0, 0, 0, 1, 0, 0};
    int result = jumpingOnClouds(sizeof(c)/sizeof(int), c);

	printf("result = %d\n", result);

    return 0;
}
