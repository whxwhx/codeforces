#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define red(a) for(d[a] = 0; d[a] <= 10; d[a]++)
#define F f[d[1]][d[2]][d[3]][d[4]]
using namespace std;
int c[5], f[11][11][11][11];
int d[5];
bool check() { return d[1] == 0 && d[2] == 0; }

void upd(int &a, int b) { if (a == -1 || a > b) a = b; }

int tmp[5];
int work() {
	rep(i,1,4) tmp[i] = c[i];
	int ans = 0; int t = min(c[1], c[2]); c[1] -= t, c[2] -= t, c[3] += t; ans += t;
	if (c[1]) {
		int t = c[1] / 3;
		c[1] -= t * 3, c[3] += t; ans += t * 2;
		if (c[1]) ans = -1;
	} else if (c[2]) {
		int t = c[2] * 2 / 3; ans += t;
		if (c[2] * 2 != t * 3) ans = -1;
	}
	rep(i,1,4) c[i] = tmp[i];
	return ans;
}

bool ok(int x) { return 0 <= d[x] && d[x] <= 10; }

struct sta { int d[5]; } q[12 * 12 * 12 * 12];
sta get() { sta x; rep(i,1,4) x.d[i] = d[i]; return x; }
void bfs() {
	memset(f, -1, sizeof(f)); int l = 0, r = 0;
	red(1) red(2) red(3) red(4) if (check()) { F = 0;  q[r++] = get(); }
	while (l < r) {
		sta x = q[l++];
		rep(i,1,4) d[i] = x.d[i];
		int tmp = F;
		rep(i,1,4) rep(j,0,3) {
			d[i]--, d[i - 1]++;
			d[j]--, d[j + 1]++;
			if (ok(1) && ok(2) && ok(3) && ok(4)) if (F == -1) F = tmp + 1, q[r++] = get();
			d[i]++, d[i - 1]--;
			d[j]++, d[j + 1]--;
		}
	}
}

int main() {
	int n; scanf("%d",&n);
	rep(i,1,n) { int x; scanf("%d",&x); c[x]++; }
	d[0] = c[0] = 1000;
	bfs();

	int ans = -1;

	red(1) red(2) red(3) red(4) if (F != -1) {
		rep(i,1,4) c[i] -= d[i];
		if (c[1] >= 0 && c[2] >= 0 && c[3] >= 0 && c[4] >= 0) { int tmp = work(); if (tmp != -1) upd(ans, tmp + F); }
		rep(i,1,4) c[i] += d[i];
	}

	printf("%d\n",ans);
	return 0;
}
