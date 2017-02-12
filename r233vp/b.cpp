#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 2010, M = 20010;
double f[N][N];
bool vis[2][N];
int main() {
	int n, m; scanf("%d%d",&n,&m);
	f[0][0] = 0;
	rep(i,0,n) rep(j,0,n) {
		if (i == 0 && j == 0) continue;
		double t = n * n - (n - i) * (n - j);
		f[i][j] = (n - i) * j * (j > 0 ? f[i][j - 1] : 0) + i * (n - j) * (i > 0 ? f[i - 1][j] : 0) + i * j * (i > 0 && j > 0 ? f[i - 1][j - 1] : 0) + n * n;
		f[i][j] /= t;
	}
	int a = n, b = n;
	rep(i,1,m) {
		int x, y; scanf("%d%d",&x,&y);
		if (!vis[0][x]) vis[0][x] = true, a--;
		if (!vis[1][y]) vis[1][y] = true, b--;
	}
	printf("%.6lf\n",f[a][b]);
	return 0;
}
