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
const int N = 2010, M = 510;
char s[N], p[N]; 
int f[N][M], g[N][N];
int main() {
	scanf("%s",s + 1); int n = strlen(s + 1);
	scanf("%s",p + 1); int l = strlen(p + 1);
	f[0][l] = 1;
	rep(i,1,n) {
		f[i][l] = i + 1;
		rep(j,0,l - 1) f[i][j] = (s[i] == p[l - j] ? f[i - 1][j + 1] : f[i - 1][j]);
	}

	rep(i,1,n) g[0][i] = -n;
	rep(i,1,n) {
		g[i][0] = g[i - 1][0];
		rep(j,1,n) g[i][j] = max(g[i - 1][j - 1], g[i - 1][j]);
		int t = f[i][0];
		if (t) {
			int del = (i - t + 1) - l;
			rep(j,del,n) g[i][j] = max(g[i][j], g[t - 1][j - del] + 1);
		}
	}
	rep(i,0,n) printf("%d ",g[n][i]); printf("\n");
	return 0;
}