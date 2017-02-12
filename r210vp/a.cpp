#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 5010, inf = 1000000000;
int mx[N], d[N], t[N], l[N], r[N], a[N];
int main() {
	int n, m; scanf("%d%d",&n,&m);
	rep(i,1,n) mx[i] = inf, d[i] = 0;
	rep(i,1,m) { 	
		scanf("%d%d%d%d",&t[i],&l[i],&r[i],&a[i]);
		if (t[i] == 1) { 
			rep(j,l[i],r[i]) d[j] += a[i];
		} else {
			rep(j,l[i],r[i]) mx[j] = min(mx[j], a[i] - d[j]);
		}
	}
	rep(i,1,n) d[i] = 0;
	rep(i,1,m) if (t[i] == 1) {
		rep(j,l[i],r[i]) d[j] += a[i];
	} else {
		int ans = -inf;
		rep(j,l[i],r[i]) ans = max(ans, mx[j] + d[j]);
		if (ans != a[i]) { printf("NO\n"); return 0; }
	}
	printf("YES\n");
	rep(i,1,n) printf("%d ",mx[i]); printf("\n");
	return 0;
}
