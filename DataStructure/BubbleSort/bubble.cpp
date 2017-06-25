#include <algorithm>    //swap
#include <iostream>
#include <stdlib.h>      //printf
#include "print.h"

using namespace std;

void bubblesort(int A[], int n) {
    int cmp = 0, swp = 0;
    while (n--) {
        for (int i = 0; i < n; i++) {
            if (A[i] > A[i + 1]) {
                swap(A[i],A[i+1]);
                swp++;
                printf("%3d:",n);
                print(A,n,i,i+2);
            }
            cmp++;
        }
    }
    printf("#comparison=%d,#swap=%d\n",cmp,swp);
}
