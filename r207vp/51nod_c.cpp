#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Rep(i,a) for(int i = 0; i < (a); i++)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)//(a)!
#define dep(i,a,b) for(int i = (a); i >= (b); i--)
#define ab(a) ((a) > 0 ? (a) : -(a))
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;

const int N = 110, mod = 1000000000 + 7;
int a[N][N][N], d[N];

int miu(int x) {
	int ans = 1;
	for(int p = 2; p <= x; p++) if (x % p == 0) {
		x /= p; if (x % p == 0) return 0;
		ans = -ans;
	}
	return ans;
}

int n;
int b[N][N];

int q[N], l, r;
void bfs() {
	l = r = 1;
	rep(i,1,n) if (!d[i]) q[r++] = i;
	while (l < r) {
		int x = q[l++];
		rep(i,1,n) if (b[x][i]) { d[i] -= b[x][i]; if (!d[i]) q[r++] = i; }
	}
}

int w[100010], ans[N], x[100010], y[100010], mu[N];

int f[N];
void calc(int t) {
	rep(i,1,n) f[i] = 0;
	rep(i,1,n) {
		int x = q[i]; f[x]++;
		rep(j,i+1,n) if (a[t][x][q[j]]) f[q[j]] = (f[q[j]] + 1LL * f[x] * a[t][x][q[j]]) % mod;
	}
	ans[t] = 0;
	rep(i,1,n) ans[t] = (ans[t] + f[i] - 1) % mod;
}

int main() {
	int m; scanf("%d%d",&n,&m);
	rep(i,1,100) mu[i] = miu(i);
	rep(t,1,m) { 
		scanf("%d%d%d",&x[t],&y[t],&w[t]); b[x[t]][y[t]]++; d[y[t]]++;
		rep(i,1,100) if (w[t] % i == 0 && mu[i]) a[i][x[t]][y[t]]++;
	}
	bfs(); 
//	rep(i,1,n) cout <<q[i]<<' '; cout <<endl;
	rep(i,1,100) if (mu[i]) calc(i);
	int A = 0; rep(i,1,100) A = (A + 1LL * ans[i] * mu[i]) % mod; if (A < 0) A += mod;
	printf("%d\n",A);
	int T; scanf("%d",&T);
	rep(t0,1,T) {
		int t, w0; scanf("%d%d",&t,&w0);
		rep(i,1,100) if ((w[t] % i == 0) != (w0 % i == 0) && mu[i]) {
			a[i][x[t]][y[t]] -= (w[t] % i == 0);
			a[i][x[t]][y[t]] += (w0 % i == 0);
			calc(i);
		}
		w[t] = w0;
		int A = 0; rep(i,1,100) A = (A + 1LL * ans[i] * mu[i]) % mod; if (A < 0) A += mod;
		printf("%d\n",A);
	}
	return 0;
}