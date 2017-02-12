#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 160, inf = (1LL << 31) - 1;
int d[N * N], a[N][N];
struct mat{ bool a[N][N]; } T, A, C, f[32];
int ta[N][6], tb[6][N];
mat operator * (const mat &a, const mat &b) {
	rep(i,1,150) 
		for(int c = 1, j = 1; c <= 5; c++, j += 30) 
		{ ta[i][c] = 0; rep(k,0,29) if (a.a[i][j + k]) ta[i][c] |= 1 << k; }
	rep(i,1,150) 
		for(int c = 1, j = 1; c <= 5; c++, j += 30) 
		{ tb[c][i] = 0; rep(k,0,29) if (b.a[j + k][i]) tb[c][i] |= 1 << k; }
	rep(i,1,150) rep(j,1,150) {
		C.a[i][j] = false;
		rep(k,1,5) C.a[i][j] |= (ta[i][k] & tb[k][j]) > 0;
	}
	return C;
}
mat tmp;
int main() {
	int n, m; scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,n) a[i][j] = inf;
	rep(i,1,m) { int x, y, d; scanf("%d%d%d",&x,&y,&d); a[x][y] = min(a[x][y], d); }
	int l = 0; rep(i,1,n) rep(j,1,n) if (a[i][j] <= inf) d[++l] = a[i][j]; 
	sort(d + 1, d + l + 1); l = (int)(unique(d + 1, d + l + 1) - d) - 1; 
	int ans = 0; 
	d[l + 1] = inf; T.a[1][1] = true; A.a[n][n] = true;
	rep(t,1,l) if (d[t] < inf) {
		if (t == 1 && d[t] != 0) break;
		rep(i,1,n) rep(j,1,n) if (a[i][j] == d[t]) A.a[i][j] = true;
		f[0] = A; rep(i,1,30) if (ans <= d[t + 1] - (1 << i)) f[i] = f[i - 1] * f[i - 1];
		dep(i,30,0) if (ans <= d[t + 1] - (1 << i)) {
			tmp = T * f[i]; 
			if (!tmp.a[1][n]) T = tmp, ans += 1 << i;
		}
		if (ans < d[t + 1]) { printf("%d\n",ans + 1); return 0; }
	}
	printf("Impossible\n");
	return 0;
}