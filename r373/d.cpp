#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 200010, mod[2] = {1000000000 + 7, 1000000000 + 9};

struct edge{ int to, pre; } e[N << 1]; int u[N], l = 1;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

struct sta { int h[2], l; } f[N << 1], ans[N]; int al = 0; 
inline bool operator < (const sta &a, const sta &b) {
	if (a.h[0] < b.h[0]) return true;
	else if (a.h[0] == b.h[0] && a.h[1] < b.h[1]) return true;
	else if (a.h[0] == b.h[0] && a.h[1] == b.h[1] && a.l < b.l) return true;
	else return false;
}
inline bool operator == (const sta &a, const sta &b) {
	rep(d,0,1) if (a.h[d] != b.h[d]) return false;
	return a.l == b.l;
}
bool vis[N << 1];
int d[N], c[N], pw[N << 1][2];

sta calc(sta *s, int sl) {
	sort(s + 1, s + sl + 1);
	sta ans; ans.h[0] = ans.h[1] = ans.l = 1;
	rep(i,1,sl){
		rep(d,0,1) 
			ans.h[d] = (ans.h[d] * 1LL * pw[s[i].l][d] + s[i].h[d]) % mod[d];
		ans.l += s[i].l;
	}
	rep(d,0,1) ans.h[d] = (ans.h[d] << 1) % mod[d]; ans.l++;
	return ans;
}

sta dfs(int from) {
	if (vis[from]) return f[from]; else vis[from] = true;
	int x = e[from].to;
	sta s[5]; int sl = 0;
	reg(i,x) if (i != (from ^ 1)) s[++sl] = dfs(i);
	f[from] = calc(s, sl);
	return f[from];
}

int main() {
	int n; scanf("%d",&n);
	rep(i,1,n - 1) { int a, b; scanf("%d%d",&a,&b); ins(a, b), ins(b, a); d[a] ++, d[b] ++; }
	rep(d,0,1) pw[0][d] = 1; rep(i,1,n << 2) rep(d,0,1) pw[i][d] = (pw[i - 1][d] << 1) % mod[d]; //be careful
	rep(i,1,n) if (d[i] < 4) ins(i, n + i), ins(n + i, i), c[i] = l;
	rep(i,1,n) if (d[i] < 4) ans[++al] = dfs(c[i]);
	sort(ans + 1, ans + al + 1); al = unique(ans + 1, ans + al + 1) - ans - 1;
	printf("%d\n",al);
	return 0;
}