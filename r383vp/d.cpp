#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i++)
using namespace std;
const int N = 500010;
int n, h[1 << 22], fa[N], r[N], f[N], sz[N], son[N], dep[N];

struct edge{ int to, pre; }e[N << 1]; int u[N], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

void dfs(int x, int f) {
	dep[x] = dep[f] + 1, son[x] = 0, sz[x] = 1;
	reg(i,x) if (v != f) dfs(v, x), sz[x] += sz[v], son[x] = (sz[v] > sz[son[x]] ? v : son[x]);
}
int pre[N], dfn = 0, id[N], top[N];
void build(int x, int f) {
	id[pre[x] = ++dfn] = x;
	if (son[x]) top[son[x]] = top[x], build(son[x], x);
	reg(i,x) if (v != son[x] && v != f) top[v] = v, build(v, x);
}

void upd(int &a, int b) { if (b > a) a = b; }

vector< pair<int, int> > a[N];
#define pb push_back
#define mp make_pair
void st(int s, int x, int val) { if (!h[s]) a[top[x]].pb(mp(s, 0)); upd(h[s], val); }

int main() {
	scanf("%d",&n); int tg = 0;
	rep(i,2,n) { char c; scanf("%d %c",&fa[i],&c); r[i] = c - 'a'; ins(i, fa[i]), ins(fa[i], i); }
	dfs(1,0), top[1] = 1, build(1,0);
	dep(t,n,1) {
		int x = id[t];
		//calc_h 
		if (h[tg]) upd(f[x], h[tg] - dep[x]);
		rep(k,0,21) if (h[tg ^ (1 << k)]) upd(f[x], h[tg ^ (1 << k)] - dep[x]);
		//add_x
		st(tg, x, dep[x]);
		//calc_ch
		reg(i,x) if (v != fa[x] && v != son[x]) {
			int L = a[v].size(); 
			Rep(j,L) {
				int s = a[v][j].first, val = a[v][j].second;
				if (h[s ^ tg]) upd(f[x], h[s ^ tg] + val - (dep[x] << 1));
				rep(k,0,21) if (h[s ^ tg ^ (1 << k)]) upd(f[x], h[s ^ tg ^ (1 << k)] + val - (dep[x] << 1));
			}
			Rep(j,L) {
				int s = a[v][j].first, val = a[v][j].second;
				st(s ^ tg, x, val);
			}
		}
		//pass
		tg ^= 1 << r[x];
		if (top[x] == x) {
			int L = a[x].size();
			Rep(i,L) {
				int &s = a[x][i].first, &val = a[x][i].second;
				val = h[s], h[s] = 0, s ^= tg;
			}
			tg = 0;
		}
	}
//	int L = a[2].size();
//	Rep(i,L) cout <<a[2][i].first<<' '<<a[2][i].second<<endl;
	dep(i,n,2) upd(f[fa[i]], f[i]);
	rep(i,1,n) printf("%d ",f[i]); printf("\n");
	return 0;
}