#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 4010, mod = 1000000000 + 7;
int f[N], c[N][N], g[N];
int main() {
	int n; scanf("%d",&n);
	rep(i,0,N - 10) {
		c[i][0] = c[i][i] = 1;
		rep(j,1,i - 1) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
	f[0] = g[0] = 1;
	rep(i,1,n) {
		f[i] = 0; rep(j,2,i) f[i] = (f[i] + 1LL * c[i - 1][j - 1] * f[i - j]) % mod;
		f[i] = (f[i] + 2LL * f[i - 1]) % mod;
		g[i] = 0; rep(j,1,i) g[i] = (g[i] + 1LL * c[i - 1][j - 1] * g[i - j]) % mod;
	}
	int ans = f[n] - g[n]; ans %= mod; if (ans < 0) ans += mod;
	printf("%d\n",ans);
	return 0;
}
