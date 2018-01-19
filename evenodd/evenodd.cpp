#include <cstdio>
#include <string>

char num[101][62];
bool b[101];
int n;

bool check_eo(char a[62]) {
    int i = strlen(a)-1;
    return (a[i] == '2' || a[i] == '4' || a[i] == '6' ||
            a[i] == '8' || a[i] == '0');
}

main() {
    //
    FILE *fin  = fopen ("evenodd.in", "r");
    FILE *fout = fopen ("evenodd.out", "w");
    //
    fscanf(fin,"%d", &n); 
    
    for (int i=1; i<=n; i++) {
        fscanf(fin,"%s", num[i]);
    }
    
    for (int i=1; i<=n; i++) {
        if (check_eo(num[i])) b[i] = true;
        else b[i] = false;    
    }
    
    for (int i=1; i<n; i++) {
        if (b[i]) fprintf(fout,"even\n");
            else fprintf(fout,"odd\n");
    }
        if (b[n]) fprintf(fout,"even");
            else fprintf(fout,"odd");
    
    return 0;
}
