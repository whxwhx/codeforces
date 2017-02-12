#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 200010;
int val[N];

struct edge { int to, pre; } e[N << 1];
int u[N], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

int n, k; 
int sum[N], s[N], rt = 0;
void getrt(int x, int f) {
	sum[x] = val[x], s[x] = 0;
	reg(i,x) if (v != f) getrt(v, x), sum[x] += sum[v], s[x] = max(s[x], sum[v]);
	s[x] = max(s[x], (k << 1) - sum[x]), rt = s[x] < s[rt] ? x : rt;
}

typedef long long LL;
LL ans = 0;
void dfs(int x, int f, int dis) {
	ans += 1LL * dis * val[x];
	reg(i,x) if (v != f) dfs(v, x, dis + 1);
}

int main() {
	cin >>n>>k; s[0] = (k << 1) + 1;
	rep(i,1,(k << 1)) { int x; cin >>x; val[x]++; }
	rep(i,1,n - 1) { int a, b; cin >>a>>b; ins(a, b), ins(b, a); }
	getrt(1, 0);
	dfs(rt, 0, 0);
	cout <<ans<<endl;
	return 0;
}