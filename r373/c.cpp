#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
typedef long long LL;
const int N = 100010, mod = 1000000000 + 7;

struct mat{ int a[2][2]; }F;
mat c;
mat operator * (const mat &a, const mat &b) { 
	rep(i,0,1) {
		rep(j,0,1) {
			LL s = 0;
			rep(k,0,1) s += 1LL * a.a[i][k] * b.a[k][j];
			c.a[i][j] = s % mod;
		}
	}
	return c;
}

mat operator + (const mat &a, const mat &b) {
	rep(i,0,1) rep(j,0,1) c.a[i][j] = (a.a[i][j] + b.a[i][j]) % mod;
	return c;
}

mat pow(mat a, int b) {
	mat w; rep(i,0,1) rep(j,0,1) w.a[i][j] = (i == j);
	for(;b;b >>= 1, a = a * a) if (b & 1) w = w * a;
	return w;
}

int num[N][2]; 

namespace seg {
	#define mid ((l + r) >> 1)
	#define lc (x << 1)
	#define rc (lc | 1)
	#define lcq lc, l, mid
	#define rcq rc, mid + 1, r
	int a, b;
	mat c, s[N << 2], tag[N << 2];
	void push(int x, int l, int r) {
		s[x] = tag[x] * s[x];
		if (l < r) tag[lc] = tag[x] * tag[lc], tag[rc] = tag[x] * tag[rc];
		rep(i,0,1) rep(j,0,1) tag[x].a[i][j] = (i == j);
	}
	void add(int x, int l, int r) {
		if (a <= l && r <= b) { tag[x] = c * tag[x]; push(x, l, r); }
		else {
			push(x, l, r);
			(a <= mid ? add(lcq) : push(lcq)), (b > mid ? add(rcq) : push(rcq));
			s[x] = s[lc] + s[rc];
		}
	}
	int qry(int x, int l, int r) {
		push(x, l, r);
		if (a <= l && r <= b) return s[x].a[0][0];
		else return ( (a <= mid ? qry(lcq) : 0) + (b > mid ? qry(rcq) : 0) ) % mod;
	}
	void build(int x, int l, int r) {
		rep(i,0,1) rep(j,0,1) tag[x].a[i][j] = (i == j);
		if (l == r) s[x].a[0][0] = num[l][0], s[x].a[1][0] = num[l][1];
		else build(lcq), build(rcq), s[x] = s[lc] + s[rc];
	}
}

int main() {
	F.a[0][0] = F.a[0][1] = F.a[1][0] = 1; F.a[1][1] = 0;
	mat s; s.a[0][0] = 0, s.a[1][0] = 1;
	int n, m; scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&num[i][0]);
	rep(i,1,n) {
		mat tmp = pow(F, num[i][0]) * s; 
		num[i][0] = tmp.a[0][0];
		num[i][1] = tmp.a[1][0];
	}
	seg::build(1, 1, n);
	rep(i,1,m) {
		int tp, l, r, x; scanf("%d",&tp);
		if (tp == 1) {
			scanf("%d%d%d",&l,&r,&x);
			seg::a = l, seg::b = r, seg::c = pow(F, x);
			seg::add(1, 1, n);
		} else {
			scanf("%d%d",&l,&r); seg::a = l, seg::b = r;
			printf("%d\n",seg::qry(1, 1, n));
		}
	} 
	return 0;
}