#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 1010, M = 30010, inf = 2000000001;
int n, m, s, t;
typedef unsigned int uLL;

struct edge{ int to, pre, w, c; }e[M << 1]; int u[N], l = 0;
void ins(int a, int b, int c, int d) { e[++l] = (edge){b, u[a], c, d}, u[a] = l; }
#define v e[i].to
#define ew e[i].w
#define ec e[i].c
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

bool vis[M];

int fa[N], pre[N], dfn = 0, id[N], ed[N];
void dfs(int x, int f) { fa[x] = f, pre[x] = ++dfn; reg(i,x) if (!pre[v]) vis[id[v] = ec] = true, dfs(v, x); ed[x] = dfn; }

int x[M], y[M], w[M], c0[N], c1[N];

uLL Hash[N];
int main() {
	srand(233);
	cin >>n>>m; cin >>s>>t;
	rep(i,1,m) {
		cin >>x[i]>>y[i]>>w[i];
		ins(x[i], y[i], w[i], i), ins(y[i], x[i], w[i], i);
	}
	dfs(s, 0);
	rep(i,1,m) if (!vis[i]) {
		if (pre[x[i]] < pre[y[i]]) swap(x[i], y[i]);
		uLL tmp = rand() * rand() * rand();
		for(int t = x[i]; t != y[i]; t = fa[t]) {
			c0[t]++, c1[t] = i, Hash[t] ^= tmp;
		}
	}
	if (!pre[t]) {
		printf("0\n");
		printf("0\n");
		return 0;
	}

	int ans = inf, ans0, ans1, ansc;
	rep(i,1,n) if (i != s && pre[i] <= pre[t] && pre[t] <= ed[i]) {
		if (c0[i] <= 1) {
			if (w[id[i]] + w[c1[i]] < ans) 
				ans = w[id[i]] + w[c1[i]], ansc = c0[i] + 1, ans0 = id[i], ans1 = c1[i];
		}
		rep(j,1,n) if (pre[i] <= pre[j] && pre[j] <= ed[i] && c0[j] == c0[i] && Hash[i] == Hash[j]) {
			if (pre[t] < pre[j] || pre[t] > ed[j]) {
				if (w[id[i]] + w[id[j]] < ans) 
					ans = w[id[i]] + w[id[j]], ansc = 2, ans0 = id[i], ans1 = id[j];
			}
		}
	}
	if (ans == inf) printf("-1\n"); else {
		printf("%d\n",ans);
		printf("%d\n",ansc);
		printf("%d ",ans0);
		if (ansc == 2) printf("%d\n",ans1);
	}
	return 0;
}