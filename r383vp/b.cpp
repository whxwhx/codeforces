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

const int N = 1010, W = 2010;

int f[N], a[N], b[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int F[W], G[W];

void upd(int &a, int b) { if (b > a) a = b; } 

int main() {
	int n, m, w; scanf("%d%d%d",&n,&m,&w);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) scanf("%d",&b[i]);
	rep(i,1,n) f[i] = i;
	rep(i,1,m) {
		int x, y; scanf("%d%d",&x,&y);
		x = find(x), y = find(y); f[x] = y;
	}
	rep(i,1,n) find(i);
	rep(i,1,n) if (f[i] == i) {
		rep(k,0,w) G[k] = F[k]; int sa = 0, sb = 0;
		rep(j,1,n) if (f[j] == i) { sa += a[j], sb += b[j]; rep(k,0,w) upd(F[k + a[j]], G[k] + b[j]); }
		rep(k,0,w) if (k + sa <= w) upd(F[k + sa], G[k] + sb);
	}
	cout <<F[w]<<endl;
	return 0;
}