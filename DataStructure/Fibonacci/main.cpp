#include <iostream>

#include "Fib.h"

using namespace std;

long long fibIte(int n) {
    long long f = 1, g = 0;
    while (0 < n--) {
        g += f;
        f = g - f;
    }
    return g;
}

long long fibBR(int n) {
    return (2 > n) ? (long long) n : fibBR(n - 1) + fibBR(n - 2);
}

long long fibLR(int n, long long &prev) {
    if (n == 0) {
        prev = 1;
        return 0;
    } else {
        long long prevPrev;
        prev = fibLR(n - 1, prevPrev);
        return prevPrev+prev;
    }
}

int main(int argc, char *argv[]) {
    if (2 > argc) {
        fprintf(stderr, "Usage:%s <rank>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    //依次计算Fibonacci各项
    printf("\n---------------------class Fib---------------------\n");
    Fib fib(0);
    for (int i = 0; i < n; i++, fib.next()) {
        printf("fib(%2d)=%d\n", i, fib.get());
    }
    for (int i = 0; i <= n; i++, fib.prev()) {
        printf("fib(%2d)=%d\n", n - i, fib.get());
    }

    printf("\n---------------------Iteration---------------------\n");
    for (int i = 0; i < n; i++) {
        printf("fibIte(%2d)=%22lld\n", i, fibIte(i));
    }

    printf("\n---------------------Liner Recursion---------------------\n");
    for (int i = 0; i < n; i++) {
        long long f;
        printf("fibLR(%2d)=%22lld\n", i, fibLR(i, f));
    }

    printf("\n---------------------Binary Recursion---------------------\n");
    for (int i = 0; i < n; i++) {
        printf("fibBR(%2d)=%22lld\n", i, fibBR(i));
    }

    return 0;
}