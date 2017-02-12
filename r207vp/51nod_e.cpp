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

const int N = 200010, mod = 1000000000 + 7;

char s[N];

struct edge{ int to, pre; } e[N << 1]; int u[N], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

struct node{ node *trans[26], *par; int l; }T[N * 2], *S = &T[1], *nd[N], *p = &T[1];
int tl = 1;
node *nn(){ return &T[++tl]; }
void add(int x){
	node *w = p;
	p = nn(), nd[ p->l = w->l + 1 ] = p;
	for(; w && !w->trans[x]; w = w->par) w->trans[x] = p;
	if (!w) p->par = S;
	else {
		node *q = w->trans[x];
		if (w->l + 1 == q->l) p->par = q;
		else {
			node *r = nn(); *r = *q, r->l = w->l + 1;
			p->par = q->par = r;
			for(; w && w->trans[x] == q; w = w->par) w->trans[x] = r;
		}
	}
}

int sz[N], son[N], dep[N], fa[N];
void dfs(int x) {
	sz[x] = 1, son[x] = 0;
	reg(i,x) 
		dep[v] = dep[x] + 1, fa[v] = x, dfs(v), sz[x] += sz[v], son[x] = sz[v] > sz[son[x]] ? v : son[x];
}
int pre[N], top[N], dfn = 0;
void build(int x) {
	pre[x] = ++dfn;
	if (son[x]) top[son[x]] = top[x], build(son[x]);
	reg(i,x) if (v != son[x]) top[v] = v, build(v);
}

int s0[N];

namespace seg{
	#define mid ((l + r) >> 1)
	#define lc (x << 1)
	#define rc (lc | 1)
	#define lcq lc, l, mid
	#define rcq rc, mid + 1, r
	int s[N << 3], d[N << 3], a, b, c;
	void push(int x, int l, int r) {
		s[x] = ( s[x] + 1LL * d[x] * (s0[r] - s0[l - 1]) ) % mod;
		if (l < r) d[lc] += d[x], d[rc] += d[x];
		d[x] = 0;
	}
	void add(int x, int l, int r) {
		if (a <= l && r <= b) { d[x] += c; push(x, l, r); }  else {
			push(x, l, r);
			if (a <= mid) add(lcq); else push(lcq);
			if (b >  mid) add(rcq); else push(rcq);
			s[x] = (s[lc] + s[rc]) % mod;
		}
	}
	int sum(int x, int l, int r) {
		push(x, l, r);
		if (a <= l && r <= b) return s[x];
		else return ((a <= mid ? sum(lcq) : 0) + (b > mid ? sum(rcq) : 0)) % mod;
	}
}

void Add(int x) {
	while (x) {
		seg::a = pre[top[x]], seg::b = pre[x], seg::c = 1; seg::add(1, 1, tl);
		x = fa[top[x]];
	}
}

int qry(int x) {
	int ans = 0;
	while (x) {
		seg::a = pre[top[x]], seg::b = pre[x]; ( ans += seg::sum(1, 1, tl) ) %= mod;
		x = fa[top[x]];
	}
	return ans;
}
int n;
void buildsam() {
	rep(i,1,n) add(s[i] - 'a');
	rep(i,2,tl) ins(T[i].par - T, i);
	dfs(1); build(1);
	rep(i,2,tl) s0[pre[i]] = 1LL * (T[i].l - T[i].par->l) % mod;
	rep(i,1,tl) s0[i] = (s0[i - 1] + s0[i]) % mod;
}


int main() {
	scanf("%d",&n); scanf("%s",s + 1);
	int sum = 0, ans = 0; buildsam();
	rep(i,1,n) {
		sum = (sum + qry(nd[i] - T)) % mod, ans = (ans + sum) % mod;
		Add(nd[i] - T); if (ans < 0) ans += mod; printf("%d\n",ans);
	}	
	return 0;
}