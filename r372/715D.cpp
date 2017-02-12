#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
typedef long long LL;
const int N = 310;
int n, m, k, a[N], b[N], c[N], d[N], l = 0;
void add(int a1, int b1, int c1, int d1) { l++, a[l] = a1, b[l] = b1, c[l] = c1, d[l] = d1; }
int W[N], wl = 0;
int main() {
	LL T; scanf("%lld",&T);
	n = 2, m = 2; add(1, 2, 2, 2), add(2, 1, 2, 2);
	while (T) W[++wl] = T % 6, T /= 6;
	dep(i,wl,1){
		n += 2, m += 2; int w = W[i];
		if (w < 3) add(n - 3, m - 1, n - 2, m - 1); else w -= 3;
		add(n - 1, m - 3, n - 1, m - 2);
		if (!w) add(n, m - 3, n, m - 2); else w--;
		if (!w) add(n - 3, m, n - 2, m); else w--;
		if (m - 4 > 0) add(n, m - 4, n, m - 3);
		if (n - 4 > 0) add(n - 4, m, n - 3, m);
		if (i == 1) break;
		if (m - 4 > 0) add(n + 1, m - 4, n + 1, m - 3);
		if (n - 4 > 0) add(n - 4, m + 1, n - 3, m + 1);
		rep(d,-2,-1) add(n, m + d, n + 1, m + d);
		rep(d,-2,-1) add(n + d, m, n + d, m + 1);
	}
	printf("%d %d\n",n,m);
	printf("%d\n",l);
	rep(i,1,l) printf("%d %d %d %d\n",a[i],b[i],c[i],d[i]);
	return 0;
}
