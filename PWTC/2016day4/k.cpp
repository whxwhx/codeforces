#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a, _b = b; i <= _b; i++)
using namespace std;
const int N = 200010, M = 500010;

int d[N], a[M], b[M], n;
struct edge{ int to, pre; }e[M * 2]; int u[N], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; d[a]++; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

int pre[N], dfn = 0, low[N];
bool cut[N];
void tarjan(int x){
	pre[x] = low[x] = ++dfn; int cnt = 0;
	reg(i,x) {
		if (!pre[v]) {
			cnt++, tarjan(v), low[x] = min(low[x], low[v]); 
			if (low[v] >= pre[x]) cut[x] = true; 
		} else low[x] = min(low[x], pre[v]);
	}
}
int bel[N], cnt = 0;
void color(int x, int c){ bel[x] = c; reg(i,x) if (!bel[v] && !cut[v]) color(v, c); }
void init(){ rep(i,1,n) if (!cut[i] && !bel[i]) color(i, ++cnt); }

int L = 0, ans[N], sz[N];
bool vis[N];

int D[N];

int main(){
	int m; scanf("%d%d",&n,&m);
	rep(i,1,m){ scanf("%d%d",&a[i],&b[i]); ins(a[i], b[i]), ins(b[i], a[i]); }
	
	rep(i,1,n) if (d[i] & 1) { printf("0\n"); return 0; }
	tarjan(1); rep(i,1,n) if (!pre[i]) { printf("0\n"); return 0; }
	cut[1] = true;

	init(); rep(i,1,n) if (!cut[i]) sz[bel[i]]++; else { 
		int x = i;
		reg(i,x) if (!cut[v]) 
		{ int c = bel[v]; if (!vis[c]) sz[c]++, vis[c] = true; D[c]++; }
		reg(i,x) if (!cut[v]) vis[bel[v]] = false;
	}
	
	rep(i,1,m){ int ba = bel[a[i]], bb = bel[b[i]]; if (ba == bb) D[ba]++; }

	rep(i,1,n) if (!cut[i]){ if (m - d[i] == n - 2) ans[++L] = i; } else {
		int x = i;
		reg(i,x) if (!cut[v]) { int c = bel[v]; D[c]--; }
		
		int t = 0;

		reg(i,x) if (!cut[v]) { 
			int c = bel[v]; 
			if (!vis[c]) { 
				if (D[c] == sz[c] - 2) t++; 
				vis[c] = true;
			}
		}

		reg(i,x) if (!cut[v]) vis[bel[v]] = false;
		reg(i,x) if (!cut[v]) { int c = bel[v]; D[c]++; }

		if (t == cnt) ans[++L] = i;
	}

	printf("%d\n",L);
	rep(i,1,L) printf("%d ",ans[i]); printf("\n");
	return 0;
}