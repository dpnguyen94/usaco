/*
ID: ndchiph1
PROG: shopping
LANG: C++
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include <stdio.h>
#include <memory.h>
#include <limits.h>

using namespace std;

#define NODEBUG

#define mp make_pair
#define pb push_back

typedef map<int, int> offer;

int n;
int aname[5], acnt[5], oname[100][5], ocnt[100][5], oprice[100];
int dp[6][6][6][6][6];

map<int,int> trans;


void input() {
    int k, z;
   
    //
    memset(oname, -1, sizeof(oname));
    memset(aname, -1, sizeof(aname));
   
    // read offers
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &k);
        for (int j=0; j<k; j++) scanf("%d%d", &oname[i][j], &ocnt[i][j]);
        scanf("%d", &oprice[i]);
    }
    
    // read needs
    scanf("%d", &k);
    for (int i=0; i<k; i++) {
        scanf("%d%d%d", &aname[i], &acnt[i], &z);
        oname[n][0] = aname[i]; ocnt[n][0] = 1; oprice[n++] = z;
    }   
}

bool relevant(int toname[5], int tocnt[5]) {
    bool ok;
    for (int i=0; i<5; i++) if (toname[i] != -1) {
        ok = false;
        for (int j=0; j<5; j++) if (toname[i] == aname[j]) {
            if (tocnt[i] <= acnt[j]) ok = true;
            break;
        }
        if (!ok) return false;
    }
    return true;
}

void init() {
    // trans
    for (int i=0; i<5; i++) if (aname[i] != -1) trans[aname[i]] = i;
    
    // filter irrelevant offers
    int tn, toname[100][5], tocnt[100][5], toprice[100];
    tn = n;
    memcpy(toname , oname , sizeof(oname ));
    memcpy(tocnt  , ocnt  , sizeof(ocnt  ));
    memcpy(toprice, oprice, sizeof(oprice));
    memset(ocnt, 0, sizeof(ocnt));
    
    n = 0;
    for (int i=0; i<tn; i++) {
        if (!relevant(toname[i], tocnt[i])) continue;
        
        for (int j=0; j<5; j++)  {
            if (toname[i][j] == -1) break;
            for (int k=0; k<5; k++) if (toname[i][j] == aname[k]) { 
                ocnt[n][ trans[aname[k]] ] = tocnt[i][j];
                break; 
            }
        }
        oprice[n++] = toprice[i];
    }
    
    // fix needs
    int tmp[5];
    memcpy(tmp, acnt, sizeof(acnt));
    memset(acnt, 0, sizeof(acnt));
    for (int i=0; i<5; i++) if (aname[i] != -1) acnt[ trans[aname[i]] ] = tmp[i];
    
    
    #ifdef DEBUG
    printf("need: "); for (int i=0; i<5; i++) printf("%d ", acnt[i]); printf("\n");
    
    printf("num of offers: %d\n", n);
    for (int i=0; i<n; i++) {
        printf("%d   : ", oprice[i]);
        for (int j=0; j<5; j++) printf("%d ", ocnt[i][j]);
        printf("\n");
    }
    #endif
}

int go(int x[5]) {
    //
    int &res = dp[ x[0] ][ x[1] ][ x[2] ][ x[3] ] [ x[4] ];
    if (res >= 0) return res;
    res = INT_MAX;
       
    //
    int tmp[5];
    bool ok;
    for (int i=0; i<n; i++) {
        //
        ok = true;
        memset(tmp, 0, sizeof(tmp));
        for (int j=0; j<5; j++) {
            tmp[j] = x[j] - ocnt[i][j];
            if (tmp[j] < 0) { ok = false; break; }
        }
        if (!ok) continue;   
        
        //
        res = min(res, oprice[i] + go(tmp));
    }
    
    return res;
}

void process() {
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0][0] = 0;
    printf("%d\n", go(acnt));
}

int main() {
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
    
    input();
    init(); 
    process();
    return 0;
}
