#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 200010, mod = 1000000000 + 7;

int v[N], fa[N], l = 1;
int op[N], dd[N];

vector<int> ch[N];
#define pb(a) push_back(a)

int sz[N], son[N], dep[N];
void dfs(int x) {
	sz[x] = 1, son[x] = 0;
	for(auto v : ch[x]) 
		dep[v] = dep[x] = 1, dfs(v),
		sz[x] += sz[v], son[x] = sz[v] > sz[son[x]] ? v : son[x];
}

int pre[N], top[N], dfn = 0;
void build(int x) {
	pre[x] = ++dfn; 
	if (son[x]) top[son[x]] = top[x], build(son[x]);
	for(auto v : ch[x]) if (v != son[x]) top[v] = v, build(v);
}

int pw(int a, int b) { int w = 1; for(;b;b >>= 1, a = 1LL * a * a % mod) if (b & 1) w = 1LL * w * a % mod; return w; }

#define lc (x << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)
#define lcq lc, l, mid
#define rcq rc, mid + 1, r

int pd[N * 4], det[N * 4], d[N];

void push(int x, int l, int r) {
	if (l < r) {
		int t = det[x]; det[x] = 0;
		(det[rc] += t) %= mod;
		(det[lc] += t * 1LL * pd[rc] % mod) %= mod;
	}
}

void modi_d(int x, int l, int r, int a, int d) {
	push(x, l, r);
	if (l == r) { 
		int inv = pw(d, mod - 2); 
		det[x] = 1LL * det[x] * pd[x] % mod * inv % mod;
		pd[x] = d;
	}
	else (a <= mid ? modi_d(lcq, a, d) : modi_d(rcq, a, d)), pd[x] = 1LL * pd[lc] * pd[rc] % mod;
}

int qry(int x, int l, int r, int a) {
	push(x, l, r);
	if (l == r) return det[x] * 1LL * pd[x] % mod;
	else return (a <= mid ? qry(lcq, a) : qry(rcq, a));
}

int qry(int x) {
	int t = qry(1, 1, dfn, pre[x]);
	if (t < 0) t += mod; return t;
}

int add_v(int x, int l, int r, int a, int b, int &d) {
	if (a <= l && r <= b) det[x] = (det[x] + d) % mod, d = 1LL * d * pd[x] % mod;
	else {
		push(x, l, r);
		if (b >  mid) add_v(rcq, a, b, d);
		if (a <= mid) add_v(lcq, a, b, d);
	}
}

void add_v(int x, int d) {
	while (x) {
		add_v(1, 1, dfn, pre[top[x]], pre[x], d);
		x = fa[top[x]];
	}
}

void add(int x) {
	d[x] = 1, modi_d(1, 1, dfn, pre[x], 1);
	int tmp = qry(fa[x]), inv = pw(d[fa[x]], mod - 2);
	int delta = (1LL * tmp * inv % mod * (d[fa[x]] + 1) % mod - tmp) % mod;

	add_v(fa[x], delta * 1LL * inv % mod);

	d[fa[x]]++, modi_d(1, 1, dfn, pre[fa[x]], d[fa[x]]);

	add_v(x, v[x]);
}

int main() {
	scanf("%d",&v[1]);
	int q; scanf("%d",&q);
	rep(i,1,q) {
		scanf("%d",&op[i]);
		if (op[i] == 1) {
			dd[i] = ++l;
			scanf("%d%d",&fa[l],&v[l]);
		} else scanf("%d",&dd[i]);
	}
	
	rep(i,1,l) if (fa[i]) ch[fa[i]].pb(i);
	
	dep[1] = 1, dfs(1);
	top[1] = 1, build(1);

	d[1] = 1, modi_d(1, 1, dfn, pre[1], 1);
	add_v(1, v[1]);
	rep(i,1,q) {
		if (op[i] == 1) add(dd[i]);
		else printf("%d\n",qry(dd[i]));
	}
	return 0;
}