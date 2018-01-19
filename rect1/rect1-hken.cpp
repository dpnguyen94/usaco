/*
ID: hoangducv1
PROG: rect1
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;


struct rect { int x, y, u, v, col; };

int a, b, n;
rect c[1000];

int len[2];
rect s[2][10000];
int cnt[2501];


void input() {
     scanf("%d%d%d", &a, &b, &n);
}

void process2(int prev, int next) {
     //
     rect r;
     len[next] = 0;
     scanf("%d%d%d%d%d", &r.x, &r.y, &r.u, &r.v, &r.col);
     
     //
     for (int i=0; i<len[prev]; i++) {
         //
         rect &p = s[prev][i];
         if (r.u<p.x || r.x>p.u || r.v<p.y || r.y>p.v) 
            { s[next][ len[next]++ ] = p; continue; }
         
         // chia hinh chu nhat cu thanh nhieu hinh` con
         if (r.x > p.x) s[next][ len[next]++ ] 
            = (rect) {p.x, max(r.y,p.y), r.x, p.v, p.col};
         if (r.y > p.y) s[next][ len[next]++ ] 
            = (rect) {p.x, p.y, min(r.u,p.u), r.y, p.col};
         if (r.u < p.u) s[next][ len[next]++ ] 
            = (rect) {r.u, p.y, p.u, min(r.v,p.v), p.col};
         if (r.v < p.v) s[next][ len[next]++ ] 
            = (rect) {max(r.x,p.x), r.v, p.u, p.v, p.col};
     }
     
     //
     s[next][ len[next]++ ] = r;
}

void process() {
     //
     len[0] = 1; s[0][0] = (rect) {0, 0, a, b, 1};
     for (int i=0; i<n; i++) {
         process2(i%2, 1-i%2);
     }
     
     //
     int k = 1 - (n-1)%2;
     memset(cnt, 0, sizeof(cnt));
     for (int i=0; i<len[k]; i++) {
         rect &p = s[k][i];
         cnt[ p.col ] += (p.u-p.x) * (p.v-p.y);
     }
     
     //
     for (int i=1; i<=2500; i++) if (cnt[i]>0) printf("%d %d\n", i, cnt[i]);
}

int main() {
    //
    freopen("rect1.in", "r", stdin);
    freopen("rect1.out", "w", stdout);
    
    //
    input();
    process();
    return 0;
}
