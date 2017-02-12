#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 1000010;
struct edge{ int a, b, c; }e[N];
bool operator < (const edge &a, const edge &b) { return a.c < b.c; }
int n, m;

#define pb(a) push_back(a)

struct us{
	vector<int> fa[N], sz, cnt;
	void init(){ fa.clear(); rep(i,1,sz) fa[i].pb(i); cnt = 0; }
	int find(int x) { return fa[x] == x ? x : f[x] = find(f[x]); }
	void merge(int a, int b){
		a = find(a), b = find(b);
		if (a != b) fa[a] = b, cnt++;
	}
}mst, con[N], g;

bool vis[N];

namespace Graph{ 
	struct edge{ int to, pre; }e[N * 2]; int u[N], l = 0;
	void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
	#define v e[i].to
	#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)
	int fa[N], r[N], sz[N], son[N];
	void dfs(int x, int f){ 
		fa[x] = f; int c = 1; sz[x] = 1; son[x] = 0;
		reg(i,x) if (v != f) dfs(v, x), r[v] = ++c, sz[x] += sz[v], son[x] = sz[v] > sz[son[x]] ? v : son[x];
		con[x].sz = c; con[x].init();
	}
	int dep[N], top[N], pre[N], dfn = 0, id[N];
	void build(int x, int f){
		id[ pre[x] = ++dfn ] = x;
		if (son[x]) top[son[x]] = top[x], build(son[x], x);
		reg(i,x) if (v != f) top[v] = v, dep[v] = dep[x] + 1, build(v, x);
	}
	int lca(int a, int b){
		int ta = top[a], tb = top[b];
		while (ta != tb){
			if (dep[ta] < dep[tb]) swap(ta, tb), swap(a, b);
			a = ta, ta = top[a];
		}
		return dep[a] < dep[b] ? a : b;
	}
	int kth(int x, int d){
		while (dep[top[x]] > d) x = top[x];
		return id[ pre[x] - ( dep[x] - d) ];
	}
	void addedge(int a, int b, int i){
		int lc = lca(a, b);
		if (lc != a && lc != b && con[lc].cnt < sz - 1) {
			la = kth(a, dep[lc] + 1), lb = kth(b, dep[lc] + 1);
			con[lc].merge(r[la], r[lb]); 
			if (con[lc].cnt == sz - 1) ans[lc] = i;
		}
		
	}
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,m) scanf("%d%d%d",&e[i].a,&e[i].c,&e[i].c);
	sort(e + 1, e + m + 1); mst.sz = n; mst.init(); int mx = 0, cnt = 0;
	rep(i,1,m) {
		int fa = mst.find(e[i].a), fb = mst.find(e[i].b);
		if (fa != fb) { cnt++; vis[i] = true; mx = i; mst.fa[fa] = fb; Graph::ins(e[i].a, e[i].b), Graph::ins(e[i].b, e[i].a); }
	}
	if (cnt < n - 1){ rep(i,1,n) printf("-1 "); printf("\n"); }

	Graph::dfs(1, 0); Graph::build(1, 0); g.sz = n; g.init();

	rep(i,1,n) ans[i] = -1;
	rep(i,1,mx) if (!vis[i]) Graph::addedge(e[i].a, e[i].b, i);
	rep(i,1,n) if (ans[i] != -1) ans[i] = mx;
	rep(i,mx+1,m) Graph::addedge(e[i].a, e[i].b, i);
	rep(i,1,n) printf("%d ",ans[i] == -1 ? -1 : e[ans[i]].c); printf("\n");
	return 0;
}