/*
ID: ndchiph1
PROG: scavhunt
LANG: C++
*/

#include <stdio.h>

#define MAX 6001

int p, q, m;
int cp[MAX], cq[MAX];

void enter() {
    scanf("%d%d", &p, &q);
    if (p > q) m = p; 
        else m = q;
}

void process() {
    //count;
    int i = 0, j = 0;
    for (int t=1; t<=m; t++) {
        if (p % t == 0) cp[i++] = t;
        if (q % t == 0) cq[j++] = t;
    }
    
    for (m=0; m<i; m++) 
        for (int n=0; n<j; n++) printf("%d %d\n", cp[m], cq[n]); 
        
}

main () {
    freopen("scavhunt.in", "r", stdin);
    freopen("scavhunt.out", "w", stdout);
    
    enter();
    process();
    
    return 0;
}
