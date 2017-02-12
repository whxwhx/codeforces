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
int a[N]; bool vis[N];
int ans = 0, pre[N];
int main() {
	int n; scanf("%d",&n); rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) if (!vis[i]) {
		int x = i, cnt = 0;
		while (!vis[x]) { vis[x] = true; x = a[x]; cnt++; }
		if (cnt == 1) ans = i;
	}
	if (ans) {
		printf("YES\n");
		rep(i,1,n) if (i != ans) printf("%d %d\n",i, ans);
	} else {
		memset(vis, false, sizeof(vis));
		rep(i,1,n) if (!vis[i]) {
			int x = i, cnt = 0;
			while (!vis[x]) { vis[x] = true; x = a[x]; pre[x] = ++cnt; }
			if (cnt % 2 > 0) { printf("NO\n"); return 0; }
			if (cnt == 2) ans = i;
		}
		if (ans) {
			printf("YES\n");
			printf("%d %d\n",ans, a[ans]);
			rep(i,1,n) if (i != ans && i != a[ans]) {
				if (pre[i] & 1) printf("%d %d\n",i,ans);
				else printf("%d %d\n",i, a[ans]);
			}
		} else printf("NO\n");
	}
	return 0;
}