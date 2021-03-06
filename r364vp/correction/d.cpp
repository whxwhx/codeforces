#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 100010, M = 320;
int s[N];

struct seg{ int l, r, b, id; }a[N];
inline bool operator < (const seg &a, const seg &b) { return a.b < b.b || (a.b == b.b && a.r < b.r); }

int cnt[N], c[N], pre[N], nxt[N];

void add(int x) {
	int t = cnt[x];
	c[t + 1]++; 
	if (nxt[t] != t + 1) (nxt[t + 1] = nxt[t]) [pre] = t + 1, nxt[pre[t + 1] = t] = t + 1;
	c[t]--; 
	if (!c[t]) pre[t][nxt] = nxt[t], nxt[t][pre] = pre[t];
	cnt[x] ++;
}

void del(int x) {
	int t = cnt[x];
	c[t - 1]++;
	if (pre[t] != t - 1) (pre[t - 1] = pre[t]) [nxt] = t - 1, pre[ nxt[t - 1] = t ] = t - 1;
	c[t]--;
	if (!c[t]) pre[t][nxt] = nxt[t], nxt[t][pre] = pre[t];
	cnt[x] --;
}

int q[2][N], C[2][N], l[2], r[2];
int getmin() {
	if (l[1] == r[1]) return 0;
	if (l[0] == r[0]) return 1;
	return (q[0][l[0]] < q[1][l[1]]) ? 0 : 1;
}
#define ql(d) q[d][l[d]]
#define qr(d) q[d][r[d]]
#define cl(d) C[d][l[d]]
#define cr(d) C[d][r[d]]

int calc() {
	l[0] = l[1] = r[0] = r[1] = 1; int ans = 0;
	for(int i = nxt[0]; i; i = nxt[i]) qr(0) = i, cr(0) = c[i], r[0]++;
	while ((r[0] - l[0]) * cl(0) + (r[1] - l[1]) * cl(1) > 1) {
		int d = getmin();
		if (cl(d) > 1) {
			int t = cl(d) / 2; cl(d) -= t << 1;
			ans += (t << 1) * ql(d);
			qr(1) = ql(d) << 1, cr(1) = t; r[1]++;
			if (!cl(d)) l[d]++;
		} else {
			int sum = 0;
			sum += ql(d); l[d]++; 
			int d1 = getmin();
			sum += ql(d1); cl(d1)--; if (!cl(d1)) l[d1]++;
			ans += sum; qr(1) = sum, cr(1) = 1, r[1]++;
		}
	}
	return ans;
}

int ans[N];
int main() {
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&s[i]);
	int q; scanf("%d",&q);
	rep(i,1,q) { scanf("%d%d",&a[i].l,&a[i].r); a[i].b = a[i].l / M; a[i].id = i; }
	sort(a + 1, a + q + 1); 
	int l = 1, r = 1; c[0] = n + 1, nxt[0] = 1, c[1] = 1, pre[1] = 0; cnt[s[1]] = 1;
	rep(i,1,q) {
		while (r < a[i].r) add(s[++r]);
		while (l > a[i].l) add(s[--l]);
		while (l < a[i].l) del(s[l++]);
		while (r > a[i].r) del(s[r--]);
//		cout <<l<<' '<<r<<endl;
		ans[a[i].id] = calc();
	}
	rep(i,1,q) printf("%d\n",ans[i]);
	return 0;
}