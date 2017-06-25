#include <iostream>
#include <stdlib.h>
#include "print.h"

using namespace std;

void bubblesort(int A[],int n); //precompiled violent bubble sort

//将A[0,n]随机打乱
void shuffle(int A[], int n) {
    while (1 < n) {
        swap(A[rand() % n], A[--n]);
    }
}

//将A[lo,hi]随机打乱
void shuffle(int A[],int lo,int hi){
    shuffle(A+lo,hi-lo);
}

//构造随机数函数
void randomArray(int A[], int n, int seed) {
    srand(seed);
    for (int i = 0; i < n; i++) {
        A[i] = i;
    }
    shuffle(A,0,n);
}

int main(int argc, char *argv[]) {
    int n = 0;
    if (1 < argc) {
        n = atoi(argv[1]);
    }
    if (n < 0)n = 0;

    int *A = (int *) malloc(n * sizeof(int));
    unsigned int seed = (unsigned int) time(NULL);

    randomArray(A,n,seed);
    printf("\n========== BubbleSort algorithm #0 ==========\n");
    printf("--> ");
    print(A,n);

    bubblesort(A,n);

    return 0;
}