/*
ID : ndchiph1
PROG : beads
LANG : C++
*/

#include <stdio.h>
#include <string.h>

char s[701],t[701];
int l,p[701];
bool b[701];

main() {
    freopen ("beads.in", "r", stdin);
    freopen ("beads.out", "w", stdout);
    
    //input    
    scanf("%d", &l);
    scanf("%s", s);
    //init
    for (int i=1; i<=l; i++) p[i] = 0;
    //
    int j;
    char c;
    //
    for (int i=1; i<=l; i++) {
        //sao s sang t
        strcpy(t,s);
        //ghep i ki tu dau tien cua s vao t
        strncat(t,s,i);
        //
        for (j=1; j<l+i; j++) b[j] = true;
        //dau
        j = i;
        if (t[i] == 'w') {
            while (t[j] == 'w') j++;
            c = t[j];
            j = i;
            while (t[j] == 'w' || t[j] == c) {
                if (j > l+i-1) break;
                p[i]++;
                b[j] = false;
                j++;
            }
        }
        else {
            j = i;
            while (t[j] == t[i] || t[j] == 'w') {
                if (j > l+i-1) break;
                p[i]++;
                b[j] = false;
                j++;
            }
        }
        
        //cuoi
        if (t[l+i-1] == 'w') {
            j = l+i-1;
            while (t[j] == 'w') j--;
            c = t[j];
            j = l+i-1;
            while (t[j] == 'w' || t[j] == c) {
                if (j < i) break;
                if (b[j]) p[i]++;
                j--;
            }
        }
        else {
            j = l+i-1;
            while (t[j] == t[l+i-1] || t[j] == 'w') {
                if (j < i) break;
                if (b[j]) p[i]++;
                j--;
            }
        }
    }
    //output
    int max = p[1];
    for (int i=2; i<=l; i++) {
        if (p[i] > max) max = p[i];
    }
    //for (int i=1; i<=l; i++) printf("%d ", p[i]);
    printf("%d\n", max);
    
    return 0;
}
