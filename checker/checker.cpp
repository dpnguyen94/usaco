/*
ID: ndchiph1
PROG: checker
LANG: C++
*/

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAX 13
using namespace std;

int n, res;
bool a[MAX+1], b[2*MAX+1], c[2*MAX];
int d[MAX+1];

void init() {
    memset(a,true,sizeof(a));
    memset(b,true,sizeof(b));
    memset(c,true,sizeof(c));
}

void attempt2(int i) {
    int t;
    if (i == 1) t = n/2;
    else t = n;
    
    for (int j=1; j<= t; j++) {
        if (a[j] && b[i+j] && c[i-j+n]) {
            d[i] = j;
            if (i == n) res++;
            else {
                a[j] = b[i+j] = c[i-j+n] = false;
                attempt2(i+1);
                a[j] = b[i+j] = c[i-j+n] = true;
            }
        }
    }
}

void process() {
    init();
    //
    res = 0;
    attempt2(1);
    res *= 2;
    
    if (n % 2 == 1) {
        int j = n/2 + 1;
        a[j] = b[1+j] = c[1-j+n] = false;
        attempt2(2);
    }
    printf("%d\n", res);
}

void printres() {
    res++;
    for (int i=1; i<n; i++) printf("%d ", d[i]);
    printf("%d\n", d[n]);
    
    if (res == 3) {
        process();
        exit(0);
    }
}

void attempt1(int i) {
    for (int j=1; j<= n; j++) {
        if (a[j] && b[i+j] && c[i-j+n]) {
            d[i] = j;
            if (i == n) printres();
            else {
                a[j] = b[i+j] = c[i-j+n] = false;
                attempt1(i+1);
                a[j] = b[i+j] = c[i-j+n] = true;
            }
        }
    }
}

main() {
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);
    
    scanf("%d", &n);
    init();
    attempt1(1);
        
    return 0;
}
