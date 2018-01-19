/* 
ID: ndchiph1
PROG: milk2
LANG: C++
*/
#include <stdio.h>

int n;
long long a[5001], b[5001];

FILE *in, *out;

void input() {
    fscanf(in,"%d", &n);
    for (int i=1; i<=n; i++) fscanf(in,"%ld%ld", &a[i], &b[i]);
}

void swap(long long& x, long long& y){
    int z;
    z = x; 
    x = y; 
    y = z;
}


void sort(int fi, int la) {
    if (fi >= la) return;
    //
    int i = fi, j = la;
    long long t = a[(fi+la)/2];
    //
    do {
        while (a[i] < t) i++;
        while (a[j] > t) j--;
        //
        if (i <= j) {
            if (i < j) {
                swap(a[i],a[j]);
                swap(b[i],b[j]);
            }
            i++; j--;
        }
    } while (i <= j);
    //
    sort(fi,j);
    sort(i,la);
}

long long max(long long x, long long y) {
    if (x > y) return x;
    return y;
}

void process() {
    long long cont, idle;
    //
    sort(1,n);//sort theo thoi gian bat dau;
    //init
    cont = b[1] - a[1]; idle = 0;
    //
    for (int i=2; i<=n; i++) {
        if (a[i] <= b[i-1]) {
            if (b[i] < b[i-1]) {
                if (b[i-1] - a[i-1] > cont) cont = b[i-1] - a[i-1];
                    a[i] = a[i-1];
                    b[i] = b[i-1];
            }
            else {
                if (b[i] - a[i-1] > cont) cont = b[i] - a[i-1];
                    a[i] = a[i-1];
            }
        }
        else {
            if (a[i] - b[i-1] > idle) idle = a[i] - b[i-1];
            cont = max(cont, max(b[i-1] - a[i-1], b[i] - a[i]));
        }
    }
    //
    fprintf(out,"%ld",cont);
    fprintf(out," %ld\n", idle);
}

main() {
    in = fopen ("milk2.in", "r");
    out = fopen ("milk2.out", "w");
    
    input();
    process();
    //
    
    return 0;
}
