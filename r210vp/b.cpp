#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 2010, inf = 2000000000;
int n, k, a[N], f[N];
int ab(int x) { return x < 0 ? -x : x; }
bool check(int L) {
	rep(i,1,n) {
		f[i] = i - 1;
		rep(j,1,i - 1) if (ab(a[i] - a[j]) <= 1LL * L * (i - j)) f[i] = min(f[i], f[j] + (i - j - 1));
		if (f[i] + (n - i) <= k) return true;
	}
	return false;
}
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",&a[i]);
	int l = -1, r = inf;
	while (l + 1 < r) {
		int mid = (1LL * l + r) >> 1;
		if (check(mid)) r = mid; else l = mid;
	}
	printf("%d\n",r);
	return 0;
}