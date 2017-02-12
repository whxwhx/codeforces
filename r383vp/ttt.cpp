#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 500010;
char c[N];
int f[N], ch[N * 24][2], val[N * 24], tag[N], sz[N], tl = 0, n, nd[N], dep[N], r[N], fa[N];
void upd(int &a, int b) { if (b > a) a = b; }
bool debug = false;
int calc(int x, int y, int f, int d) {
	if (!x || !y) return 0;
	if (d == -1) return val[x] + val[y];
	else {
		int ans = 0;
		rep(i,0,1) upd(ans, calc(ch[x][i], ch[y][i ^ ((f >> d) & 1)], f, d - 1));
		return ans;
	}
}

int merge(int x, int y, int f, int d) {
	if (!x || !y) return x | y;
	if (d == -1) { upd(val[x], val[y]); return x; } 
	else {
		rep(i,0,1) ch[x][i] = merge(ch[x][i], ch[y][i ^ ((f >> d) & 1)], f, d - 1);
		return x;
	}
}

int main() {
	scanf("%d",&n);
	rep(i,2,n) scanf("%d %c",&fa[i],&c[i]), r[i] = c[i] - 'a', dep[i] = dep[fa[i]] + 1;
	rep(i,1,n) {
		nd[i] = ++tl; rep(j,1,22) ch[tl][0] = tl + 1, tl++; 
		val[tl] = dep[i]; sz[i] = 1;
	}
	dep(i,n,2) {
		if (i == 2) debug = true;
		upd(f[fa[i]], f[i]); tag[i] ^= 1 << r[i];
//		if (sz[i] > sz[fa[i]]) swap(tag[i], tag[fa[i]]), swap(nd[i], nd[fa[i]]);

		int T = tag[i] ^ tag[fa[i]];
		upd(f[fa[i]], calc(nd[i], nd[fa[i]], T, 21) - (dep[fa[i]] << 1));
		rep(j,0,21) upd(f[fa[i]], calc(nd[i], nd[fa[i]], T ^ (1 << j), 21) - (dep[fa[i]] << 1));
		
		nd[fa[i]] = merge(nd[fa[i]], nd[i], T, 21);
		sz[fa[i]] += sz[i];
	}
	rep(i,1,n) printf("%d ",f[i]); printf("\n");
	return 0;
}