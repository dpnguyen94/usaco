/*
ID: ndchiph1   
PROG: palsquare
LANG: C++
*/
#include <stdio.h>

int base;
int d[20];

FILE *in, *out;

long long sqr(int i) {
    return i*i;
}

bool is_palindrome(long long n) {
    int i = 0;
    long long m = n;
    //
    while (m > 0) {
        d[i++] = m%base;
        m /= base;
    }   
    //
    for (int j=0; j<i; j++) m = m*base + d[j];
    //
    return (m == n);
}

void print_palin(long long n) {
    int i = 0;
    while (n > 0) {
        d[i++] = n%base;
        n /= base;   
    }
    //
    for (int j=i-1; j>=0; j--) {
            if (d[j] >= 0 && d[j] <= 9) fprintf(out,"%d", d[j]);
            if (d[j] == 10) fprintf(out,"A");
            if (d[j] == 11) fprintf(out,"B");
            if (d[j] == 12) fprintf(out,"C");
            if (d[j] == 13) fprintf(out,"D");
            if (d[j] == 14) fprintf(out,"E");
            if (d[j] == 15) fprintf(out,"F");
            if (d[j] == 16) fprintf(out,"G");
            if (d[j] == 17) fprintf(out,"H");
            if (d[j] == 18) fprintf(out,"I");
            if (d[j] == 19) fprintf(out,"J");
            if (d[j] == 20) fprintf(out,"K");
    }
}

main() {
    in = fopen ("palsquare.in", "r");
    out = fopen ("palsquare.out", "w");
    
    fscanf(in,"%d", &base);
    //
    for (long long i=1; i<=300; i++) 
        if (is_palindrome(sqr(i))) {
            print_palin(i);
            fprintf(out," ");
            print_palin(sqr(i));
            fprintf(out,"\n");
        }
    //  
    return 0;
}
