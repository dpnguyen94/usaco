/*
ID: ndchiph1
PROG: stamps
LANG: C++
*/
#include <stdio.h> 

#define LM  2000010

using namespace std;
int k, n, amax;
int f[LM], a[100];

void input() {
    scanf("%d %d\n", &k, &n); 
    
    amax = 0;
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > amax) amax = a[i];
    }
}

void process() {
    int s = amax * k;
    
    for (int i=1; i<= s; i++) {
        for (int j=0; j<n; j++)
            if (a[j] <= i) 
                if (f[i] == 0 || f[i-a[j]] + 1 < f[i]) 
                    f[i] = f[i-a[j]] + 1;
    }
    
    int t;
    for (int i=1; ; i++) 
        if (f[i] > k || f[i] == 0) {
            t = i - 1;
            break;
        }
    
    printf("%d\n", t);
}


main() {    
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);

    input();
    process();
    
    return 0;
}
