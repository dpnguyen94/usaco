/*
ID: ndchiph1
PROG: concom
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

int n = 100;            // dat so luong cong ty la 100 luon
int a[100][100];        // a[i][j] = k: i so huu k% co phan cua j
bool c[100][100];       // c[i][j] = true: i controls j

void input() {    
    int numLine, x, y, z;
    
    scanf("%d", &numLine);
    memset(a, 0, sizeof(a));
    for (int i=0; i<numLine; i++) {
        scanf("%d%d%d", &x, &y, &z);
        a[x-1][y-1] = z;
    }
}

void process() {
    //
    memset(c, false, sizeof(c));
    for (int i=0; i<n; i++) c[i][i] = true;     // condition 1.
    
    // Phuong tap dung phuong phap dung vong while sau. Anh se giai thich ky hon.
    int tmp;
    bool stop = false;
    while (!stop) {
        //
        stop = true;
        
        //
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (!c[i][j]) { // test if i controls j
            // condition 2.
            if (a[i][j] > 50) { c[i][j] = true; stop = false; continue; }
            
            // condition 3
            tmp = 0;
            for (int k=0; k<n; k++) if (c[i][k]) tmp += a[k][j];
            if (tmp > 50) { c[i][j] = true; stop = false; }
        }
    } // end while
}

void output() {
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (i!=j && c[i][j])
        printf("%d %d\n", i+1, j+1);
}

int main() {
    //
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    
    //
    input();
    process();
    output();
    return 0;
}
