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
const int N = 200010 * 2;

struct edge{ int to, pre; } e[N << 1]; int u[N], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

bool vis[N]; int f[N];
void dfs(int x) {
	vis[x] = true;
	reg(i,x) if (!vis[v]) f[v] = f[x] ^ 1, dfs(v);
}

int a[N], b[N];

int main() {
	int n; scanf("%d",&n);
	rep(i,1,2 * n) if (i & 1) ins(i, i + 1), ins(i + 1, i);
	rep(i,1,n) {
		scanf("%d%d",&a[i],&b[i]);
		ins(a[i], b[i]), ins(b[i], a[i]);
	}
	rep(i,1,2 * n) if (!vis[i]) dfs(i);
	rep(i,1,n) if (f[a[i]]) printf("1 2\n"); else printf("2 1\n");
	return 0;
}