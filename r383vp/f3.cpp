#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 500010;

int fa[N], r[N], dep[N]; char c[N];
int tag[N * 25], ch[N * 25][2], val[N * 25], nd[N], tl = 0;
int nn(int d, int v) { 
	int x = ++tl;
	if (d == -1) val[x] = v; else ch[x][0] = nn(d - 1, v);
	return x;
}
void upd(int &a, int b) { if (b > a) a = b; }

void push(int x) {
	if (tag[x] & 1) swap(ch[x][0], ch[x][1]);
	tag[ch[x][0]] ^= tag[x] >> 1, tag[ch[x][1]] ^= tag[x] >> 1;
	tag[x] = 0;
}

int calc(int x, int y, int d) {
	if (!x || !y) return 0;
	if (d == -1) return val[x] + val[y];
	else {
		push(x), push(y); int ans = 0;
		rep(i,0,1) upd(ans, calc(ch[x][i], ch[y][i], d - 1));
		return ans;
	}
}

int merge(int x, int y, int d) {
	if (!x || !y) return x | y;
	if (d == -1) { upd(val[x], val[y]); return y; }
	else {
		push(x), push(y);
		rep(i,0,1) ch[x][i] = merge(ch[x][i], ch[y][i], d - 1);
		return x;
	}
}

int f[N];

int main() {
	int n; scanf("%d",&n);
	rep(i,2,n) scanf("%d %c",&fa[i],&c[i]), r[i] = c[i] - 'a', dep[i] = dep[fa[i]] + 1;
	rep(i,1,n) nd[i] = nn(21, dep[i]);
	dep(i,n,2) {
		int fx = fa[i]; upd(f[fx], f[i]);
		tag[nd[i]] ^= 1 << r[i]; 
		upd(f[fx], calc(nd[i], nd[fx], 21) - (dep[fx] << 1));
		rep(j,0,21) {
			tag[nd[i]] ^= 1 << j;
			upd(f[fx], calc(nd[i], nd[fx], 21) - (dep[fx] << 1));
			tag[nd[i]] ^= 1 << j;
		}
		nd[fx] = merge(nd[fx], nd[i], 21);
	}
	rep(i,1,n) printf("%d ",f[i]); printf("\n");
	return 0;
}