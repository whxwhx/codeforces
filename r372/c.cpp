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

const int N = 100010;

int n, M, inv[N];
struct edge { int to, pre, c; } e[N << 1]; int u[N], l = 0;
void ins(int a, int b, int c) { e[++l] = (edge){b, u[a], c}, u[a] = l; }
#define v e[i].to
#define ec e[i].c
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

bool vis[N];
int sz[N], s[N], sum, rt = 0;
void getrt(int x, int f){
	sz[x] = 1; s[x] = 0;
	reg(i,x) if (v != f && !vis[v]) getrt(v, x), sz[x] += sz[v], s[x] = max(s[x], sz[v]);
	s[x] = max(s[x], sum - sz[x]); 
	if (s[x] < s[rt]) rt = x;
}

LL ans = 0;

map<int, int> cnt;

void dfs(int x, int f, int d, int t, int delta) {
	d %= M; cnt[d] += delta;
	reg(i,x) if (v != f && !vis[v]) dfs(v, x, (d + 1LL * t * ec) % M, 10LL * t % M, delta);
}

void cal(int x, int f, int d, int a) {
	d %= M; ans += cnt[ 1LL * (M - d) * inv[a] % M ];
	reg(i,x) if (v != f && !vis[v]) cal(v, x, (d * 10LL + ec) % M, a + 1);
}

void cal(int x) {
	cnt.clear(); dfs(x, 0, 0, 1, 1);
	ans += cnt[0] - 1;
	reg(i,x) if (v != x && !vis[v]) {
		dfs(v, x, ec, 10, -1);
		cal(v, x, ec, 1);
		dfs(v, x, ec, 10, 1);
	}
}

void work(int x){
	vis[x] = true; cal(x);
	int tmp = sum - sz[x];
	reg(i,x) if (!vis[v]){
		sum = sz[v] < sz[x] ? sz[v] : tmp; 
		rt = 0; getrt(v, x);
		work(rt);
	}
} 
void work(){ s[rt = 0] = sum = n; getrt(1, 0); work(rt); }

int x, y;
void exgcd(int a, int b) {
	if (b == 0) { x = 1, y = 0; }
	else {
		exgcd(b, a % b);
		int t = x; x = y;
		y = t - 1LL * (a / b) * x;
	}
}

int main() {
	cin >>n>>M;
	rep(i,1,n - 1) { int a, b, c; scanf("%d%d%d",&a,&b,&c); a++, b++; ins(a, b, c), ins(b, a, c); }

	exgcd(10, M);

	int tmp = x; tmp %= M; if (tmp < 0) tmp += M;
	inv[0] = 1; rep(i,1,n) inv[i] = inv[i - 1] * 1LL * tmp % M;
	work();
	cout <<ans<<endl;
	return 0;
}