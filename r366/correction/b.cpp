#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 5010;
typedef long long LL;
const LL inf = N * 1000000000LL * 4;
LL a[N], b[N], c[N], d[N], x[N], f[N][N];
void upd(LL &a, LL b) { if (b < a) a = b; }
int main() {
	int n, s, e; scanf("%d%d%d",&n,&s,&e);
	rep(i,1,n) scanf("%lld",&x[i]);
	rep(i,1,n) scanf("%lld",&a[i]);
	rep(i,1,n) scanf("%lld",&b[i]);
	rep(i,1,n) scanf("%lld",&c[i]);
	rep(i,1,n) scanf("%lld",&d[i]);
	/*
		in: a b
		 	 x
	   out: c d
	*/
	rep(i,1,n) 
		c[i] += x[i], b[i] -= x[i], d[i] -= x[i], a[i] += x[i];
	if (s > e) {
		swap(s, e);
		rep(i,1,n) swap(a[i], c[i]), swap(b[i], d[i]);
	}	

	rep(i,0,n) rep(j,0,n) f[i][j] = inf;
	f[0][0] = 0; 
	rep(i,1,n - 1) if (i != s && i != e) {
		//add 
		rep(j,0,n) upd(f[i][j + 1], f[i - 1][j] + b[i] + d[i]);
		//link
		rep(j,1,n) if (j + (int)(i > s) >= 2) upd(f[i][j - 1], f[i - 1][j] + a[i] + c[i]);
		//extend
		rep(j,0,n) {
			if (j || i > s) upd(f[i][j], f[i - 1][j] + a[i] + d[i]);
			if (j || i > e) upd(f[i][j], f[i - 1][j] + c[i] + b[i]);
		}
	} else if (i == s){
		rep(j,0,n) upd(f[i][j], f[i - 1][j] + d[i]);
		rep(j,1,n) upd(f[i][j - 1], f[i - 1][j] + c[i]);
	} else {
		rep(j,0,n) upd(f[i][j], f[i - 1][j] + b[i]);
		rep(j,1,n) upd(f[i][j - 1], f[i - 1][j] + a[i]);
	}
	if (e == n) printf("%lld\n",f[n - 1][0] + a[n]);
	else printf("%lld\n",f[n - 1][0] + a[n] + c[n]);
	return 0;
}