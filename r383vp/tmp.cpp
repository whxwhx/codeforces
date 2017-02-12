#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define Rep(i,a) for(int i = 0; i < a; i++)
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 500010;

int n;
struct edge{ int to, pre, c; } e[N << 1]; int u[N], l = 0;
void ins(int a, int b, int c) { e[++l] = (edge){b, u[a], c}, u[a] = l; }
#define v e[i].to
#define ec e[i].c
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

int sz[N], son[N], dep[N], fa[N], r[N];
void dfs(int x, int f) {
	son[x] = 0; sz[x] = 1;
	reg(i,x) if (v != f) r[v] = ec, dep[v] = dep[x] + 1, dfs(v, x), sz[x] += sz[v], son[x] = sz[v] > sz[son[x]] ? v : son[x];
}

int pre[N], dfn = 0, id[N], top[N];
void build(int x, int f) {
	id[ pre[x] = ++dfn ] = x;
	if (son[x]) top[son[x]] = top[x], build(son[x], x);
	reg(i,x) if (v != f && v != son[x]) top[v] = v, build(v, x);
}

int f[N], h[1 << 22], tag = 0;
void upd(int &a, int b) { if (b > a) a = b; }

typedef pair<int, int> node;
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
vector<node> a[N];

int main() {
	scanf("%d",&n);
	rep(i,2,n) { char c; scanf("%d %c",&fa[i],&c); ins(fa[i], i, c - 'a'), ins(i, fa[i], c - 'a'); }
	dfs(1, 0); top[1] = 1, build(1, 0);
	dep(t,n,1) {
		int x = id[t]; 

		upd(f[x], h[tag] - dep[x]);
		rep(k,0,21) upd(f[x], h[tag ^ (1 << k)] - dep[x]);
		upd(h[tag], dep[x]);

		reg(i,x) if (v != fa[x] && v != son[x]) {
			int len = a[v].size();
			Rep(j,len) {
				int s = a[v][j].first, val = a[v][j].second;
				if (h[s ^ tag]) upd(f[x], val + h[s ^ tag] - (dep[x] << 1));
				rep(k,0,21) {
					s ^= 1 << k;
					if (h[s ^ tag]) upd(f[x], val + h[s ^ tag] - (dep[x] << 1));
					s ^= 1 << k;
				}
			}
		}

		reg(i,x) if (v != fa[x] && v != son[x]) {
			int len = a[v].size();
			Rep(j,len) {
				int s = a[v][j].first, val = a[v][j].second;
				upd(h[s ^ tag], val);
			}
		}

		if (top[x] == x) {
			tag ^= 1 << r[x];
			Rep(i,(1 << 22)) if (h[i]) a[x].pb(mp(i ^ tag, h[i]));
			memset(h, 0, sizeof(h)); tag = 0;
		} else tag ^= 1 << r[x];
	}
	dep(i,n,2) upd(f[fa[i]], f[i]);
	rep(i,1,n) printf("%d ",f[i]); printf("\n");
	return 0;
}