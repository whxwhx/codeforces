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
const int N = 110;

int a[N], p[N];

bool vis[N];

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main() {
	int n; cin >>n;
	rep(i,1,n) cin >>a[i], p[i] = a[i];
	sort(p + 1, p + n + 1);
	rep(i,1,n) if (p[i] != i) { printf("-1\n"); return 0; }
	LL ans = 1;
	rep(i,1,n) if (!vis[i]) {
		int c = 0;
		for(int x = i; !vis[x]; x = a[x]) vis[x] = true, c++;
		if (c % 2 == 0) c /= 2;
		ans = ans * (c / gcd(ans, c));
	}
	printf("%lld\n",ans); return 0;
}