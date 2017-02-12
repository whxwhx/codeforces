#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 200010;
char s[N]; int n;

namespace Tree{
	struct edge{ int to, pre; } e[N << 1]; int u[N << 1], l = 0;
	void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
	#define v e[i].to
	#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)
	int pre[N << 1], f[N << 1][19], ed[N << 1], dfn = 0;
	void dfs(int x) {
		pre[x] = ++dfn;
		reg(i,x) f[v][0] = x, dfs(v);
		ed[x] = dfn;
	}
	void build(int tl) { dfs(1); rep(j,1,18) rep(i,1,tl) f[i][j] = f[f[i][j - 1]][j - 1];}
}

namespace Seg{
	int s[N * 20], lc[N * 20], rc[N * 20], tl = 0, a, b;
	int nn(int x) { tl++; s[tl] = s[x], lc[tl] = lc[x], rc[tl] = rc[x]; return tl; }
	#define lc x[lc]
	#define rc x[rc]
	#define mid ((l + r) >> 1)
	#define lcq lc, l, mid
	#define rcq rc, mid + 1, r
	int add(int x, int l, int r) 
	{ s[x = nn(x)]++; if (l < r) (a <= mid ? lc = add(lcq) : rc = add(rcq)); return x; }
	int sum(int x, int l, int r) {
		if (a <= l && r <= b) return x[s];
		else return (a <= mid ? sum(lcq) : 0) + (b > mid ? sum(rcq) : 0);
	}
}

namespace SAM{
	struct node { node *par, *trans[26]; int l, L; } T[N << 1], *S = &T[1], *p = S, *nd[N]; int l = 1;
	void add(int x) {
		node *w = p; p = &T[++l]; nd[ p->l = w->l + 1 ] = p; p->L = n - p->l + 1;
		for(;w && !w->trans[x]; w = w->par) w->trans[x] = p;
		if (!w) p->par = S;
		else {
			node *q = w->trans[x];
			if (q->l == w->l + 1) p->par = q;
			else {
				node *r = &T[++l]; *r = *q; r->l = w->l + 1;
				p->par = q->par = r;
				for(;w && w->trans[x] == q; w = w->par) w->trans[x] = r;
			}
		}
	}
	int rt[N];
	void build() { 
		dep(i,n,1) add(s[i] - 'a'); 
		rep(i,2,l) Tree::ins(T[i].par - T, i); Tree::build(l);
		rep(i,1,n) Seg::a = Tree::pre[ nd[n - i + 1] - T ], rt[i] = Seg::add(rt[i - 1], 1, l);
	}

	void upd(int &a, int b) { if (b > a) a = b; }

	bool check(int x, int L, int R) {
		Seg::a = Tree::pre[x], Seg::b = Tree::ed[x];
		return Seg::sum(rt[R - T[x].l + 1], 1, l) != Seg::sum(rt[L], 1, l);
	}

	int q[N << 1], f[N << 1];
	void solve() {
		int l = 0, r = 0, ans = 1; { using namespace Tree; reg(i,1) q[r++] = v; }
		while (l < r) {
			int x = q[l++]; if (!f[x]) f[x] = 1;
			//calc
			int L = T[x].L, R = T[x].l + T[x].L - 1, fa = x;
			dep(i,18,0) if (Tree::f[fa][i] && !check(Tree::f[fa][i], L, R)) fa = Tree::f[fa][i];

			if (Tree::f[fa][0]) fa = Tree::f[fa][0], f[x] = max(f[x], f[fa] + 1);
			//upd
			rep(i,0,25) if (T[x].trans[i]) upd(f[ T[x].trans[i] - T ], f[x]);
			{ using namespace Tree; reg(i,x) q[r++] = v; }

			ans = max(ans, f[x]);
		}
		printf("%d\n",ans);
	}
}



int main() {
	scanf("%d",&n); scanf("%s",s + 1);
	SAM::build();
	SAM::solve();
	return 0;
}