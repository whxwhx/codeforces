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
const int N = 100110;
char s[N];

struct edge{ int to, pre, c; } e[N << 2]; int u[N], l = 1;
void ins(int a, int b, int c) { e[++l] = (edge){b, u[a], c}, u[a] = l; }
#define v e[i].to
#define ec e[i].c
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

bool vis[N];
int d[N][9], n;
typedef pair<int, int> node;
priority_queue<node> q;
void dij(int S, int t) {
	memset(vis, false, sizeof(vis));
	rep(i,1,n + 8) d[i][t] = 11;
	q.push(mp(-(d[S][t] = 0), S));
	while (!q.empty()) {
		int x = q.top().second; q.pop();
		if (vis[x]) continue; else vis[x] = true;
		reg(i,x) if (d[v][t] > d[x][t] + ec)
			d[v][t] = d[x][t] + ec, q.push(mp(-d[v][t], v));
	}
}


bool check(int x, int y, int L) {
	rep(t,1,8) if (d[x][t] + d[y][t] < L) return false;
	return true;
}

int c[8][8][8][8][8][8][8][8];

int main() {
 	scanf("%d",&n); scanf("%s",s + 1);
	rep(i,2,n) ins(i - 1, i, 2), ins(i, i - 1, 2);
	rep(i,1,n) ins(i, n + 1 + s[i] - 'a', 1), ins(n + 1 + s[i] - 'a', i, 1);
	rep(i,1,5) dij(n + i, i);

	

	int ans0 = 0; LL ans1 = 0;
	rep(i,1,n) {
		int mx = 0;
		dep(j,3,1) {
			mx |= 1 << j;
			if (mx <= 8) {
				int t[6];
				rep(k,1,5) t[k] = ((mx << 1) - d[i][k] < 0) ? 0 : ((mx << 1) - d[i][k]);

				int cnt = c[t[1]][t[2]][t[3]][t[4]][t[5]][t[6]][t[7]][t[8]];
				rep(k,-(mx >> 1) + 1,(mx >> 1) - 1) if (1 <= i + k && i + k <= n && check(i, i + k, mx)) cnt--;

				if (!cnt) mx ^= 1 << j; else {
					if (mx > ans0) ans0 = mx, ans1 = cnt;
					else if (mx == ans0) ans1 += cnt;
				}
			} else mx ^= 1 << j;
		}
	}
	cout <<ans0<<' '<<ans1 / 2<<endl;
	return 0;
}