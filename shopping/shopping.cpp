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
offer a;
vector<offer> c;
vector<int> p;

map<offer, int> dp;

void debugOffer(offer& b) {
    //printf("%d  :  ", b.size());
    for (map<int,int>::iterator it=b.begin(); it!=b.end(); it++) printf(" (%d  %d)  ", it->first, it->second);
    printf("\n");
}

void input() {
    int k, x, y, z;
    offer tmp;
    
    // read offers
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        //
        tmp.clear();
        scanf("%d", &k);
        for (int j=0; j<k; j++) {
            scanf("%d%d", &x, &y);
            tmp[x] = y;
        }

        //
        c.pb(tmp);
        scanf("%d", &x); p.pb(x);
    }
    
    // read needs
    scanf("%d", &k);
    for (int i=0; i<k; i++) {
        //
        scanf("%d%d%d", &x, &y, &z);
        a[x] = y;
        
        //
        tmp.clear(); tmp[x] = 1; c.pb(tmp); p.pb(z);
    }
    
    //
    #ifdef DEBUG
    debugOffer(a);
    #endif
}

bool relevant(offer& b) {
    for (map<int,int>::iterator it=b.begin(); it!=b.end(); it++) {
        if (a.count(it->first)==0 || a[it->first]<it->second) return false;
    }
    return true;
}

offer& fix(offer& b) {
    for (map<int,int>::iterator it=a.begin(); it!=a.end(); it++) {
        b[it->first];
    }
    return b;
}

void init() {
    // filter irrelevant offers
    vector<offer> c2 = c;
    vector<int> p2 = p;
    c.clear(); p.clear();
    
    for (int i=0; i<c2.size(); i++) {
        if (relevant(c2[i])) { c.pb(fix(c2[i])); p.pb(p2[i]); }
    }
    
    #ifdef DEBUG
    for (int i=0; i<c.size(); i++) {  printf("price: %d  ---  ", p[i]); debugOffer(c[i]); }
    printf("==================\n");
    #endif
}

int go(offer& x) {
    //
    if (dp.count(x) > 0) return dp[x];
    int &res = dp[x];
    res = INT_MAX;
    
    #ifdef DEBUG
    printf("starg go: ");
    debugOffer(x);
    #endif
    
    //
    offer tmp;
    bool ok;
    for (int i=0; i<c.size(); i++) {
        map<int,int> &b = c[i];
        
        //
        tmp.clear(); ok = true;
        for (map<int,int>::iterator it=b.begin(); it!=b.end(); it++) {
            tmp[it->first] = x[it->first] - b[it->first];
            if (tmp[it->first] < 0) { ok = false; break; }
        }
        if (!ok) continue;
        
        #ifdef DEBUG
        printf("               ");
        debugOffer(tmp);
        #endif
        
        
        //
        res = min(res, p[i] + go(tmp));
        //res <?= p[i] + go(tmp);
    }
    
    return res;
}

void process() {
    offer tmp;
    dp[fix(tmp)] = 0;
    printf("%d\n", go(a));
}

int main() {
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
    
    input();
    init(); 
    process();
    return 0;
}
