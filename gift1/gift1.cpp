/*
ID: ndchiph1  
PROG: gift1
LANG: C++
*/
#include <stdio.h>
#include <string.h>

char a[11][14],t[14],c[14];
int n,b[11];

main() {
    //
    FILE*fin = fopen ("gift1.in", "r");
    FILE*fout = fopen ("gift1.out", "w");
    //input
    fscanf(fin,"%d", &n);
    for (int i=1; i<=n; i++) fscanf(fin,"%s", a[i]);
    //init
    for (int i=1; i<=n; i++) b[i] = 0;
    //
    int x,y;    
    for (int i=1; i<=n; i++) {
        fscanf(fin,"%s", c);
        fscanf(fin,"%d%d", &x, &y);
        if (x != 0 && y != 0) {
            for (int k=1; k<=n; k++) {
                if (strcmp(c,a[k]) == 0) b[k] = b[k] - x + x%y;
            }
        }
        //
        if (y != 0) {
            for (int j=1; j<=y; j++) {
                fscanf(fin,"%s", t);
                for (int k=1; k<=n; k++) {
                    if (strcmp(t,a[k]) == 0) b[k]+= x/y;
                }
            }
        }
    }    
    //output
    for (int i=1; i<=n; i++)  fprintf(fout,"%s %d\n", a[i], b[i]);
    
    return 0;
}
