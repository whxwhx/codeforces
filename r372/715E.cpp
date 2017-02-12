#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 250 + 10, mod = 998244353;
int p[N][2], q[N], g[N], f[N][N], G[N], c[N << 1][N << 1], ans[N], d[N][2];

bool vis[N][2];
int cnt[5], fac[N];
void dfs(int x, int d, int st) { 
	vis[x][d] = true; 
	if (p[x][d]) {
		if (!vis[p[x][d]][d ^ 1]) dfs(p[x][d], d ^ 1, st); 
		else cnt[4]++;
	}
	else cnt[(st << 1) | d]++;
}

int main() {
	int n; scanf("%d",&n);
	rep(i,1,n) { 
		scanf("%d",&q[i]), p[q[i]][0] = i;
		if (q[i]) d[i][1]++;
	}
	rep(i,1,n) scanf("%d",&p[i][1]), d[p[i][1]][0]++;
	rep(i,1,n) rep(d0,0,1) if (!vis[i][d0] && !d[i][d0]) dfs(i, d0, d0);
	rep(i,1,n) rep(d0,0,1) if (!vis[i][d0]) dfs(i, d0, d0);
	int l = cnt[0]; 
//	assert(cnt[0] == cnt[3]); rep(i,0,4) cout <<cnt[i]<<' '; cout <<endl;
	fac[0] = 1; rep(i,1,n) fac[i] = 1LL * fac[i - 1] * i % mod;
	int m = n << 1;
	rep(i,0,m) {
		c[i][0] = c[i][i] = 1;
		rep(j,1,i - 1) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
	rep(i,0,n) g[i] = 1LL * fac[l] * fac[i] % mod * (l == 0 ? (i == 0 ? 1 : 0) : c[i + l - 1][l - 1]) % mod;
	f[0][0] = 1;
	rep(i,1,n) rep(j,1,i) f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] * 1LL * (i - 1)) % mod;
	int l2 = cnt[2], l1 = cnt[1];
	rep(t,0,n) {
		G[t] = 0;
		rep(k,0,l2) G[t] = (G[t] + g[k] * 1LL * f[l2 - k][t] % mod * c[l2][k]) % mod; 
	}
	rep(i,0,n) rep(t,0,i) ans[i] = (ans[i] + 1LL * f[l1 + l][i - t] * G[t] % mod) % mod;
	dep(i,n,1) if (i >= cnt[4]) ans[i] = ans[i - cnt[4]]; else ans[i] = 0;
	rep(i,1,n) printf("%d ",ans[n - i + 1]);
	printf("\n");
	return 0;
}
