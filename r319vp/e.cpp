#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
using namespace std;
const int N = 500010;
int a[N], b[N], X[N], Y[N], ind[N], nxt[N], q;
struct uset{
	int f[N], sz[N], r[N], opx[N], opy[N], l;
	void merge(int x, int y, int d) {
		if (sz[x] > sz[y]) swap(x, y);
		l++; opx[l] = x, opy[l] = y;
		f[x] = y, sz[y] += sz[x], r[x] = d;
	}
	void recall() { 
		int x = opx[l], y = opy[l]; l--;
		f[x] = x, sz[y] -= sz[x], r[x] = 0;
	}
	int find(int x, int &r0) {
		if (f[x] == x) return x;
		else return (r0 ^= r[x]), find(f[x], r0);
	}
}s[51];

int color[N];
vector<int> c[N * 4], rc[N * 4];

void add(int x, int l, int r, int A, int B, int e) {
	if (A <= l && r <= B) c[x].pb(e);
	else {
		int mid = (l + r) >> 1, lc = x << 1, rc = lc | 1;
		if (A <= mid) add(lc, l, mid, A, B, e);
		if (B >  mid) add(rc, mid + 1, r, A, B, e);
	}
}

void add(int l, int r, int e) { add(1, 1, q, l, r, e); }

void work(int x, int l, int r) {
	//addedges
	{
		int l = c[x].size();
		Rep(i,l) {
			int e = c[x][i];
			int ru = 0, rv = 0; int fu = s[color[e]].find(a[e], ru), fv = s[color[e]].find(b[e], rv);
			if (fu != fv) s[color[e]].merge(fu, fv, ru ^ rv ^ 1), rc[x].pb(color[e]);
		}
	}
	if (l == r) {
		int e = X[l], c = Y[l]; 
		int u = a[e], v = b[e];
		int ru = 0, rv = 0; int fu = s[c].find(u, ru), fv = s[c].find(v, rv);
		if (fu != fv || ru != rv) color[e] = c, add(l + 1, nxt[l] - 1, e), printf("YES\n");
		else {
			if (color[e]) add(l + 1, nxt[l] - 1, e);
			printf("NO\n");
		}
	} else { int mid = (l + r) >> 1; work(x << 1, l, mid); work((x << 1) | 1, mid + 1, r); }
	//deledges
	{ int l = rc[x].size(); Rep(i,l) s[rc[x][i]].recall(); }
	vector<int>().swap(c[x]); vector<int>().swap(rc[x]);
}

int main() {
	int n, m, k; scanf("%d%d%d%d",&n,&m,&k,&q);
	rep(c,1,k) rep(i,1,n) s[c].f[i] = i, s[c].sz[i] = 1, s[c].r[i] = 0;
	rep(i,1,m) scanf("%d%d",&a[i],&b[i]);
	rep(i,1,q) { scanf("%d%d",&X[i],&Y[i]); nxt[ ind[X[i]] ] = i, ind[X[i]] = i; }
	rep(i,1,q) if (!nxt[i]) nxt[i] = q + 1;
	work(1, 1, q);
	return 0;
}