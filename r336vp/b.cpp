#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 510;
int f[N][N], g[N][N], a[N];
int main() {
	int n; scanf("%d",&n); rep(i,1,n) scanf("%d",&a[i]);
	rep(l,1,n) {
		rep(i,1,n) {
			int j = i + l - 1; if (j > n) break;
			f[i][j] = l;
			if (a[i] == a[j]) f[i][j] = min(f[i][j], f[i + 1][j - 1]);
			rep(k,i,j - 1) f[i][j] = min(f[i][j], g[i][k] + f[k + 1][j]),
						   f[i][j] = min(f[i][j], f[i][k] + g[k + 1][j]);

			g[i][j] = l;
			if (a[i] == a[j]) g[i][j] = min(g[i][j], f[i + 1][j - 1] + 1);
			rep(k,i,j - 1) g[i][j] = min(g[i][j], g[i][k] + g[k + 1][j]);
		}
	}
	printf("%d\n",g[1][n]); 
	return 0;
}