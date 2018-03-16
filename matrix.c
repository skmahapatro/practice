#define MAX_VALUE   10
#include<stdio.h>
#include<stdlib.h>
void print_matrix(int *arr, int row, int col)
{
    int i,j;
    for (i = 0; i < row; i++, printf("\n"))
        for (j = 0; j < col; j++)
            printf("%d ", *((arr+i*row) + j));
}

void gen_matrix(int *arr, int row, int col)
{
    int i,j;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            *((arr+i*row) + j) = (rand()%10);
}

void main()
{
    int arr[3][3];
    gen_matrix((int *)arr, 3, 3);
    print_matrix((int *)arr, 3, 3);
}

