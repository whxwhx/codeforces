#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 2010, mod = 1000000000 + 7;
int a[N], b[N], f[N][N], len[N][N], g[N], c[N * 2][N * 2];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) scanf("%d",&b[i]);

	c[0][0] = 1;
	rep(i,1,n*2) {
		c[i][0] = c[i][i] = 1;
		rep(j,1,i - 1) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}

	g[0] = 1;
	rep(i,1,n) {
		g[i] = c[2 * i][i] - c[2 * i - 1][i - 1];
		rep(j,1,i - 1) g[i] -= 1LL * g[j] * c[2 * (i - j)][i - j] % mod, g[i] %= mod;
	}

	f[n + 1][n + 1] = 1; rep(i,1,n) f[n + 1][i] = 1;
	dep(i,n,1) {
		f[i][n + 1] = 1;
		dep(j,n,1) {
			if (a[i] != b[j]) f[i][j] = (f[i + 1][j] + f[i][j + 1]) % mod, len[i][j] = 0;
			else {
				int l = ( len[i][j] = len[i + 1][j + 1] + 1 );
				f[i][j] = (f[i + 1][j] + f[i][j + 1]) % mod;
				rep(k,1,l) 
					f[i][j] -= 1LL * g[k] * f[i + k][j + k] % mod, f[i][j] %= mod;
			}
		}
	}
	if (f[1][1] < 0) f[1][1] += mod;
	printf("%d\n",f[1][1]);
	return 0;
}