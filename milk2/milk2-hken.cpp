/* 
ID: hoangducv1
PROG: milk2
LANG: C++
*/
#include <stdio.h>

int n;
long long a[5001], b[5001];

FILE *in, *out;

void input() {
    fscanf(in,"%d", &n);
    for (int i=1; i<=n; i++) fscanf(in,"%ld%ld", &a[i], &b[i]);
}

void swap(long long& x, long long& y){
    int z;									// hken: x va y la long long, thi em cung phai de z la long long
    z = x; x = y; y = z;					//       trong bai nay thi ko sao, vi thuc ra 2 vai arrays a, b em cung chi can de int
}


void sort(int fi, int la) {
    if (fi >= la) return;
    //
    int i = fi, j = la;
    long long t = a[(fi+la)/2];
    //
    do {
        while (a[i] < t) i++;
        while (a[j] > t) j--;
        //
        if (i <= j) {
            if (i < j) {
                swap(a[i],a[j]);
                swap(b[i],b[j]);
            }
            i++; j--;
        }
    } while (i <= j);
    //
    sort(fi,j);
    sort(i,la);
}

void process() {
    long long cont, idle;
    //
    sort(1,n);//sort theo thoi gian bat dau;
    //init
    cont = b[1] - a[1]; idle = 0;
    //
    for (int i=2; i<=n; i++) {
        if (a[i] <= b[i-1]) {
            if (b[i] < b[i-1]) {
                // if (b[i-1] - a[i-1] > cont) cont = b[i-1] - a[i-1];	// dong nay ko can vi nhung tinh doan chi voi i-1 thi da tinh o truoc roi
                    a[i] = a[i-1];
                    b[i] = b[i-1];
            }
            else {
                if (b[i] - a[i-1] > cont) cont = b[i] - a[i-1];
                    a[i] = a[i-1];
            }
        }
        else {
            if (a[i] - b[i-1] > idle) idle = a[i] - b[i-1];
            //
			// hken: em ko can phai so sanh 'cont' voi b[i-1]-a[i-1], vi phan day da duoc tinh o truoc roi
            // if (b[i-1] - a[i-1] > b[i] - a[i]) {
            //    if (b[i-1] - a[i-1] > cont) cont = b[i-1] - a[i-1];
            //}
            //else {
                if (b[i] - a[i] > cont) cont = b[i] - a[i];
            //}
        }
    }
    //
    fprintf(out,"%ld",cont);
    fprintf(out," %ld\n", idle);
}


///------------------------------------------------------------------------
long long max(long long x, long long y)
{
	if (x > y) return x; else return y;
}

void process2()
{
	long long cont, idle, left, right;
    
	//
    sort(1,n);//sort theo thoi gian bat dau;
	cont = idle = 0;
	left = a[1]; right = b[1];		// luu lai diem trai nhat, diem phai nhat cua doa.n lie^n tu.c hie^.n gio*`

	//
	for (int i=2; i<=n; i++) {
		if (a[i] <= right) right = max(right, b[i]);			// cap. nhat diem pha?i nha^'t
		else {
			cont = max(cont, right-left);						// ko the mo rong diem phai nhat, nen ket thuc' do.an lien tuc
			idle = max(idle, a[i]-right);
			left = a[i]; right = b[i];							// tao doa.n lien tu.c mo*'i
		}
	}
	cont = max(cont, right-left);		// can cai nay cho doa.n cuoi cung

	//
    fprintf(out,"%ld",cont);
    fprintf(out," %ld\n", idle);
}
///------------------------------------------------------------------------


main() {
    in = fopen ("milk2.in", "r");
    out = fopen ("milk2.out", "w");
    
    input();
    // process();
    process2();
	//
    
    return 0;
}

