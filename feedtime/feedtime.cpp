/*
ID: ndchiph1
PROG: feedtime
LANG: C++
*/

#include <stdio.h>
#include <memory.h>

#define C 751

char g[C][C];
int w, h, v[C][C];
long long max_now;
int offx[] = {0,0,-1,1,-1,-1,1,1}, offy[] = {-1,1,0,0,-1,1,-1,1};

void enter() {
    scanf("%d%d\n", &w, &h);
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) scanf("%c", &g[i][j]);
        scanf("\n");
    }
}

void ffill(int x, int y) {
    if (v[x][y] != 0 || g[x][y] == '*' || x < 1 || x > h || y < 1 || y > w) return; 
    v[x][y] = 1; max_now++;
    for (int i=0; i<8; i++) ffill(x+offx[i],y+offy[i]);
}

void process() {
    memset(v,0,sizeof(v));
    //
    long long max = 0;
    for (int i=1; i<=h; i++) 
        for (int j=1; j<=w; j++) {
            if (v[i][j] == 0 && g[i][j] == '.') {
                max_now = 0;
                ffill(i,j);
                if (max_now > max) max = max_now;
            }
        }
    printf("%ld\n", max);
}

main () {
    freopen("feedtime.in", "r", stdin);
    freopen("feedtime.out", "w", stdout);
    
    enter();
    process();
    
    return 0;
}
